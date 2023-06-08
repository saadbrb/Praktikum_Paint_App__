#ifndef POLYGONE_H
#define POLYGONE_H
#include "graphobj.h"
#include <cmath>

class Polygone : public GraphObj
{
private:
    QVector <QPoint> punkten;
public:
    Polygone(QColor color_, bool innenMAl_,QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, innenMAl_,firstPunkt_, lastPunkt_){
        punkten.push_back(firstPunkt);
        punkten.push_back(lastPunkt);


    }
    void malen(QPainter* objkt) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_) override;
    bool isNear(const QPoint& a);

};

#endif // POLYGONE_H
