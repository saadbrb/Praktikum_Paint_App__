#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include "graphobj.h"

class Rectangle : public GraphObj {


public:

    Rectangle(QColor color_, bool innenMAl_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, innenMAl_, firstPunkt_, lastPunkt_){

    }
    void malen(QPainter* objkt, bool) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_, bool) override;
    void calcBBox(QPoint &min, QPoint &max) const override;
private:
    int with;
    int height;
    int x, y;


};


#endif // RECTANGLE_H
