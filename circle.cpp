#include <iostream>
#include "circle.h"



void Circle::malen(QPainter* objkt) {

    double a= abs(getFirstPunkt().rx()-getLastPunkt().rx());
    double b = abs(getFirstPunkt().ry()-getLastPunkt().ry());
    double c = sqrt(a*a + b*b);
    rad = (int) c;

    objkt->setPen(QPen(color,2,Qt::SolidLine));
    //einfach if(innenMAl) erstzen, wurde dann nciht wegen color mode innen gemalt

    if(innenMAl || mussGemalt){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }

    objkt->drawEllipse(getFirstPunkt(), rad,rad);

}


void Circle::setColor(QColor color_) {
    color = color_;
    mussGemalt = true;
}

void Circle::addPunkt(QPoint punkt) {

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



