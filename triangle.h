#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>
#include "graphobj.h"

class Triangle : public GraphObj
{


public:
    Triangle(QColor color_, bool innenMAl_,QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, innenMAl_,firstPunkt_, lastPunkt_){
        punkten.push_back(firstPunkt);
        punkten.push_back(lastPunkt);


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

#endif // TRIANGLE_H
