#include "graphobj.h"

QPoint GraphObj::getFirstPunkt(){

    return firstPunkt;
}
QPoint GraphObj::getLastPunkt(){
    return lastPunkt;
}
QColor GraphObj::getColor(){
    return color;
}

void GraphObj::setMussGemalt(bool frage){
    mussGemalt = frage;
}
