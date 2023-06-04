#ifndef LINE_H
#define LINE_H
#include "graphobj.h"

class Line :  public GraphObj
{

public:
    Line(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, firstPunkt_, lastPunkt_){}
    void malen(QPainter* objkt) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint startP, QPoint endeeP) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_) override;


};

#endif // LINE_H
