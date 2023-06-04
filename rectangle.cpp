#include <iostream>
#include "rectangle.h"



void Rectangle::malen(QPainter* objkt) {

    objkt->setPen(QPen(color,2,Qt::SolidLine));
    //einfach if(innenMAl) erstzen, wurde dann nciht wegen color mode innen gemalt
    if(innenMAl || mussGemalt){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }
    objkt->drawRect(x,y,with,height);



}

void Rectangle::setColor(QColor color_) {
    color = color_;
    mussGemalt = true;

}
void Rectangle::addPunkt(QPoint punkt) {
    //some code
}
void Rectangle::remov(QPoint startP, QPoint endeeP) {
    //some code
}
bool Rectangle::isSmall() {
    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}
bool Rectangle::insideTest(QPoint punkt){

    QPoint max;
    QPoint min;

    if(firstPunkt.ry() >= lastPunkt.ry()){
        max = firstPunkt;
        min = lastPunkt;
    }
    else if (lastPunkt.ry() >= firstPunkt.ry() ) {
        max = lastPunkt;
        min = firstPunkt;
    }
    return min.rx() <= punkt.rx() && min.y() <= punkt.ry() &&
            punkt.rx() <= max.rx() && punkt.ry() <= max.ry();
}
