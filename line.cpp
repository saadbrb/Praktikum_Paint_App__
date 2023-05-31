#include "line.h"

void Line::malen(QPainter *painter) {


    painter->setPen(QPen(color,2,Qt::SolidLine));
    if(innere_mal_frage){
        painter->setBrush(color);
    } else{
        painter->setBrush(Qt::NoBrush);
    }

    painter->drawLine(firstPunkt, lastPunkt);

}



bool Line::isKlein() {

    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}
void Line::addPunkt(QPoint punkt_){

}
