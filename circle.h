#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "graphobj.h"


class Circle : public GraphObj {
private:
    int rad;


public:
    Circle(QColor color_, bool innenMAl_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, innenMAl_, firstPunkt_, lastPunkt_){

    }
    void malen(QPainter* objkt) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_) override;



};


#endif // CIRCLE_H
