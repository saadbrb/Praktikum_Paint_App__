#include <iostream>
#include "rectangle.h"



void Rectangle::malen(QPainter* objkt, bool deko) {
    x = firstPunkt.rx();
    y = firstPunkt.ry();
    with = lastPunkt.rx()-firstPunkt.rx();
    height =lastPunkt.ry()-firstPunkt.ry();

    objkt->setPen(QPen(color,2,Qt::SolidLine));
    //einfach if(innenMAl) erstzen, wurde dann nciht wegen color mode innen gemalt
    if(innenMAl){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }
    objkt->drawRect(x,y,with,height);



}

void Rectangle::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}

void Rectangle::addPunkt(QPoint punkt) {
    //Kein Code erforderlich
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
    int width = abs(firstPunkt.rx() - lastPunkt.rx());
    int height = abs(firstPunkt.ry() - lastPunkt.ry());
    return (width < 2) || (height < 2);
}
bool Rectangle::insideTest(QPoint punkt){

    int minX = std::min(firstPunkt.x(), lastPunkt.x());
    int minY = std::min(firstPunkt.y(), lastPunkt.y());
    int maxX = std::max(firstPunkt.x(), lastPunkt.x());
    int maxY = std::max(firstPunkt.y(), lastPunkt.y());

    return (minX <= punkt.x() && punkt.x() <= maxX) &&
            (minY <= punkt.y() && punkt.y() <= maxY);
}

void Rectangle::calcBBox(QPoint &min, QPoint &max) const  {
    min.setX(std::min(firstPunkt.x(), lastPunkt.x()));
    min.setY(std::min(firstPunkt.y(), lastPunkt.y()));
    max.setX(std::max(firstPunkt.x(), lastPunkt.x()));
    max.setY(std::max(firstPunkt.y(), lastPunkt.y()));
}
