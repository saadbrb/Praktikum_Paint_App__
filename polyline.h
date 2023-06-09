#ifndef POLYLINE_H
#define POLYLINE_H
#include <QFrame>
#include<iostream>
#include <QPainter>
#include <QPainterPath>
#include"graphobj.h"

class Polyline: public GraphObj
{


public:
    Polyline(QColor color): GraphObj(color){

    }
    void malen(QPainter* objkt, bool) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_, bool) override;
    void calcBBox(QPoint &min, QPoint &max) const override;

private:
    QVector <QPoint> punkten;

};

#endif // POLYLINE_H
