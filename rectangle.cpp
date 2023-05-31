#include <iostream>
#include "rectangle.h"



void Rectangle::malen(QPainter *painter) {


    painter->setPen(QPen(color,2,Qt::SolidLine));
    if(innere_mal_frage){
        painter->setBrush(color);
    } else{
        painter->setBrush(Qt::NoBrush);
    }
    painter->drawRect(x,y,width,height);


}

bool Rectangle::isKlein() {

    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}
void Rectangle::addPunkt(QPoint punkt_){

}
