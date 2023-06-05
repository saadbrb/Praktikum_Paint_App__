#include <iostream>
#include "rectangle.h"



void Rectangle::malen(QPainter* objkt) {
    x = firstPunkt.rx();
    y = firstPunkt.ry();
    with = lastPunkt.rx()-firstPunkt.rx();
    height =lastPunkt.ry()-firstPunkt.ry();

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
void Rectangle::remov(QPoint punkt) {
    QPoint tpr;
    tpr.setX(punkt.rx() - firstPunkt.rx());
    tpr.setY(punkt.ry() - firstPunkt.ry());


    firstPunkt.setX(firstPunkt.rx() + tpr.rx());
    firstPunkt.setY(firstPunkt.ry() + tpr.ry());
    lastPunkt.setX(lastPunkt.rx() + tpr.rx());
    lastPunkt.setY(lastPunkt.ry() + tpr.ry());
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
