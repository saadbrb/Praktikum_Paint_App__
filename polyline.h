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
    QVector <QPoint> punkten;

public:
    Polyline(QColor color): GraphObj(color){

    }
    void malen(QPainter* objkt) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_) override;



};

#endif // POLYLINE_H
