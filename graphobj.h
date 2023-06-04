#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <QFrame>
#include <iostream>
#include <QPainter>
#include <QPainterPath>
class GraphObj {

protected:
    QColor color;
    bool innenMAl;
    QPoint firstPunkt;
    QPoint lastPunkt;
    bool mussGemalt = false;


public:
    GraphObj(QColor color_, bool innenMAl_, QPoint firstPunkt_, QPoint lastPunkt_):
        color(color_), innenMAl(innenMAl_), firstPunkt(firstPunkt_), lastPunkt(lastPunkt_)  {

    }
    GraphObj(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_):
        color(color_), firstPunkt(firstPunkt_), lastPunkt(lastPunkt_) {

    }
    GraphObj(QColor color_):
        color(color_) {

    }
    // Verbieten den Kopierkonstruktor und den Zuweisungsoperator
    GraphObj(const GraphObj&) = delete;
    GraphObj& operator=(const GraphObj&) = delete;
    virtual void malen(QPainter* objkt) = 0 ;
    virtual void addPunkt(QPoint punkt) = 0;
    virtual void remov(QPoint startP, QPoint endeeP) = 0;
    virtual bool isSmall() = 0;
    virtual bool insideTest(QPoint punkt) = 0;
    virtual void setColor(QColor color_) = 0;
    QPoint getFirstPunkt();
    QPoint getLastPunkt();
    QColor getColor();
    void setMussGemalt(bool);




};


#endif // GRAPHOBJ_H
