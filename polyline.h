#ifndef POLYLINE_H
#define POLYLINE_H
#include <QFrame>
#include<iostream>
#include <QPainter>
#include <QPainterPath>
#include"graphobj.h"

class Polyline: public GraphObj
{
private:
    QVector<QPoint>punkten;

public:
    Polyline(QColor color_): GraphObj(color_){

    }
    void addPunkt(QPoint punkt) override;
    void malen(QPainter *painter) override;


    bool isKlein() override;


};

#endif // POLYLINE_H
