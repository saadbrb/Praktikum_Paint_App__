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
    innenFrage = true;
    objkt = nullptr;
    createRadioButtons();
    polyObjkt = nullptr;


}
void Canvas::createRadioButtons()
{
    buttonGroup = new QButtonGroup(this);
    groupBox = new QGroupBox(tr("Interaction Mode"));

    QRadioButton *creatButton = new QRadioButton(tr("Creat"));
    QRadioButton *delButton = new QRadioButton(tr("Del"));
    QRadioButton *colButton = new QRadioButton(tr("Col"));
    QRadioButton *trafoButton = new QRadioButton(tr("Trafo"));

    buttonGroup->addButton(creatButton, CREAT);
    buttonGroup->addButton(delButton, DEL);
    buttonGroup->addButton(colButton, COL);
    buttonGroup->addButton(trafoButton, TRAFO);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(creatButton);
    vbox->addWidget(delButton);
    vbox->addWidget(colButton);
    vbox->addWidget(trafoButton);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(interactionModeChanged(int)));
}


QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}
void Canvas::setInnenFrage(bool frage){
    innenFrage = frage;
}


void Canvas::clearCanvas()
{
    scene.deleteAllObjkts();
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
    if(type == FREE_HAND && mode == CREAT) {
        objkt = new  class Polyline(color);
    }

}

void Canvas::setInteractionMode(int mode_){
    mode = (Canvas::InteractionMode) mode_;
}

void Canvas::setColor(QColor color_)
{

    color = color_;
}

void Canvas::interactionModeChanged(int id)
{
    // Wechseln Sie den Interaktionsmodus entsprechend der Auswahl des Benutzers
    switch(id) {
    case CREAT:
        // Code für den Erstellungsmodus
        setPrimitiveMode(CREAT);
        break;
    case DEL:
        // Code für den Löschmodus
        setPrimitiveMode(DEL);
        break;
    case COL:
        // Code für den Farbänderungsmodus
        setPrimitiveMode(COL);
        break;
    case TRAFO:
        // Code für den Transformationsmodus
        setPrimitiveMode(TRAFO);
        break;
    }
}


void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    // white background (inside parent's border)
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);
    scene.alleMalne(&painter);

    if( mode == CREAT){
        if(dragging){
            if(type == FREE_HAND){

                objkt->addPunkt(lastPunkt);
                objkt->malen(&painter);

            }
            else if(type == CIRCLE){
                objkt = new Circle(color, innenFrage, firstPunkt, lastPunkt);
                objkt->malen(&painter);
                if(!objkt->isSmall()){
                    objkt->malen(&painter);
                }
            }
            else if(type == RECTANGLE){
                objkt = new class Rectangle(color, innenFrage, firstPunkt, lastPunkt);
                if(!objkt->isSmall()){
                    objkt->malen(&painter);
                }
            }
            else if(type == LINE){
                objkt = new Line(color, firstPunkt, lastPunkt);
                if(!objkt->isSmall()){
                    objkt->malen(&painter);
                }
            }
            else if(type == POLYGON && polyObjkt == nullptr){
                polyObjkt = new  Polygone(color,innenFrage, firstPunkt, lastPunkt);

                polyObjkt->malen(&painter);

            }
            else if(type == POLYGON && polyObjkt != nullptr){

                polyObjkt->malen(&painter);

            }


        }
        if((!dragging && objkt != nullptr) || (!dragging && polyObjkt != nullptr)){
            if(polyObjkt != nullptr){

                if( polyObjkt->isNear(lastPunkt)){
                    polyObjkt->addPunkt(lastPunkt);
                    polyObjkt->malen(&painter);
                    scene.addObjkt(polyObjkt);
                    polyObjkt = nullptr;
                    painter.end();

                }
                else if (!(polyObjkt->isNear(lastPunkt))) {
                    polyObjkt->addPunkt(lastPunkt);
                    polyObjkt->malen(&painter);
                }
            }

            if(objkt != nullptr){
                if(!objkt->isSmall() ){
                    objkt->malen(&painter);
                    scene.addObjkt(objkt);
                    objkt = nullptr;
                    painter.end();
                }
            }


        }
    }
    else if ( mode == COL) {
        if(checkPress == 1){

            scene.setInnenColor(innenTestPunkt,color);
        }
    }

    else if ( mode == DEL) {
        if(checkPress == 1){

            scene.deleteItem(innenTestPunkt);
        }
    }

    else if ( mode == TRAFO) {
        if(checkPress == 1 && i == -1){


            i = scene.isSelectes(innenTestPunkt);

        }
        if (i != -1 && dragging){
            scene.setPosition(tPunkt, i);
        }
        else if (i != -1 && !dragging) {
            scene.setPosition(tPunkt, i);
            i = -1;
        }
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
            objkt = new  class Polyline(color);
        }
        firstPunkt = event->pos();
        innenTestPunkt = firstPunkt;
        checkPress = 1;
        lastPunkt = firstPunkt;

        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging) {

        lastPunkt = event->pos();
        tPunkt = event->pos();
        //checkPress = 0;


        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dragging) {
        dragging = false;

        // TODO

        lastPunkt = event->pos();
        tPunkt = event->pos();

        checkPress = 0;


        update();
    }

}

