#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include "graphobj.h"

class Rectangle : public GraphObj {

private:
    int with;
    int height;
    int x, y;
public:

    Rectangle(QColor color_, bool innenMAl_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, innenMAl_, firstPunkt_, lastPunkt_){
        x = firstPunkt.rx();
        y = firstPunkt.ry();
        with = lastPunkt.rx()-firstPunkt.rx();
        height =lastPunkt.ry()-firstPunkt.ry();
    }
    void malen(QPainter* objkt) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP, QPoint endeeP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_) override;



};


#endif // RECTANGLE_H
