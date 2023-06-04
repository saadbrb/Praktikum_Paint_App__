#include <iostream>
#include "circle.h"



void Circle::malen(QPainter* objkt) {


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
    //some code
}
void Circle::remov(QPoint startP, QPoint endeeP) {
    //some code
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



