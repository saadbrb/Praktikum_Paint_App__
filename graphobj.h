#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <QFrame>
#include <iostream>
#include <QPainter>
#include <QPainterPath>
class GraphObj {

public:
    QColor color;
    QPoint firstPunkt;
    QPoint lastPunkt;
    bool innere_mal_frage;



public:
    GraphObj();

    GraphObj(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_, bool innere_mal_frage_): color(color_),
        firstPunkt(firstPunkt_), lastPunkt(lastPunkt_), innere_mal_frage(innere_mal_frage_){}

    GraphObj(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_): color(color_),
        firstPunkt(firstPunkt_), lastPunkt(lastPunkt_){}

    GraphObj(QColor color_): color(color_){}

    virtual void addPunkt(QPoint punkt_) = 0;

    virtual void malen(QPainter *painter) = 0;

    virtual bool isKlein() = 0;

    virtual ~GraphObj(){}



};


#endif // GRAPHOBJ_H
