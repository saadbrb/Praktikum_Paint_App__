#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include "canvas.h"


Canvas::Canvas(QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);

    type = NONE;
    dragging = false;
    innereFrage = true;
    tmprGraphOb_ = nullptr;

}

Canvas::~Canvas()
{
}
void Canvas::setInnerFrage(bool frage){
    if(frage){
        innereFrage = true;
    } else {
        innereFrage = false;
    }
}


QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}

void Canvas::clearCanvas()
{
    scene.deletAllEllement();
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
    if(type == FREE_HAND){
        tmprGraphOb_ = new  class Polyline(color);
    }

}
void Canvas::setFarbe(QColor color_){

    color = color_;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    // white background (inside parent's border)
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);
    scene.displayAllEllement(&painter);


    if(dragging){
        if(type == CIRCLE){

            tmprGraphOb_ = new Circle(color, firstPunkt, lastPunkt, innereFrage);
            if(!tmprGraphOb_->isKlein()){
                tmprGraphOb_->malen(&painter);
            }
        }
        else if (type == RECTANGLE) {

            tmprGraphOb_ = new class Rectangle(color, firstPunkt, lastPunkt, innereFrage);
            if(!tmprGraphOb_->isKlein()){
                tmprGraphOb_->malen(&painter);
            }
        }
        else if (type == FREE_HAND) {
            tmprGraphOb_->addPunkt(lastPunkt);
            tmprGraphOb_->malen(&painter);


        }
        else if (type == LINE) {

            tmprGraphOb_ = new Line(color, firstPunkt, lastPunkt);
            if(!tmprGraphOb_->isKlein()){
                tmprGraphOb_->malen(&painter);
            }


        }


    }

    if(!dragging && tmprGraphOb_!=nullptr){
        if(!tmprGraphOb_->isKlein()){
            tmprGraphOb_->malen(&painter);
            scene.addElement(tmprGraphOb_);

            tmprGraphOb_ = nullptr;

        }
        painter.end();
    }


}

// TODO; implement drawing functionality for all the primitives!
// The following is just a basic example and to be removed...
/*
    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
    painter.drawLine(QPoint(2, height()/2), QPoint(width()-2, height()/2));
    painter.drawLine(QPoint(width()/2, 2), QPoint(width()/2, height()-2));
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(QPoint(width()/2, height()/2), 8, 8);
    */


void Canvas::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;

        // TODO; implement mouse interaction
        // Mouse position given as follows
        //QPoint currPos = event->pos();

        if(type == FREE_HAND){
            tmprGraphOb_ = new  class Polyline(color);
        }
        firstPunkt = event->pos();
        lastPunkt = firstPunkt;
        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging) {

        lastPunkt = event->pos();

        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dragging) {
        dragging = false;

        // TODO

        lastPunkt = event->pos();

        update();
    }
}

