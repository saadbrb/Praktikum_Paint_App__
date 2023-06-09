#include <iostream>
#include "circle.h"


void Circle::malen(QPainter* objkt, bool frage) {

    double a= abs(getFirstPunkt().rx()-getLastPunkt().rx());
    double b = abs(getFirstPunkt().ry()-getLastPunkt().ry());
    double c = sqrt(a*a + b*b);
    rad = (int) c;

    objkt->setPen(QPen(color,2,Qt::SolidLine));

    if(innenMAl ){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }
    objkt->drawEllipse(getFirstPunkt(), rad,rad);
    if(frage){
        calcBBox(min, max);
        objkt->setPen(QPen(Qt::red, 2, Qt::DashLine));
        objkt->setBrush(Qt::NoBrush);
        objkt->drawRect(QRect(min, max));
    }


}
void Circle::calcBBox(QPoint &min, QPoint &max) const  {
    min.setX(firstPunkt.x() - rad);
    min.setY(firstPunkt.y() - rad);
    max.setX(firstPunkt.x() + rad);
    max.setY(firstPunkt.y() + rad);
}


void Circle::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}

void Circle::addPunkt(QPoint punkt) {
    //Kein Code notwendig
}
void Circle::remov(QPoint punkt) {

    QPoint tpr;
    tpr.setX(punkt.rx() - firstPunkt.rx());
    tpr.setY(punkt.ry() - firstPunkt.ry());


    firstPunkt.setX(firstPunkt.rx() + tpr.rx());
    firstPunkt.setY(firstPunkt.ry() + tpr.ry());
    lastPunkt.setX(lastPunkt.rx() + tpr.rx());
    lastPunkt.setY(lastPunkt.ry() + tpr.ry());
}
bool Circle::isSmall() {
    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}


bool Circle::insideTest(QPoint punkt){
    float dx = punkt.x() - firstPunkt.x();
    float dy = punkt.y() - firstPunkt.y();
    float distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
    return distance <= rad;
}



