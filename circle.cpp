#include <iostream>
#include "circle.h"



void Circle::malen(QPainter *painter) {


    painter->setPen(QPen(color,2,Qt::SolidLine));
    if(innere_mal_frage){
        painter->setBrush(color);
    } else{
        painter->setBrush(Qt::NoBrush);
    }

    painter->drawEllipse(firstPunkt, radius,radius);

}
void Circle::addPunkt(QPoint punkt_){

}



bool Circle::isKlein() {

    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}


