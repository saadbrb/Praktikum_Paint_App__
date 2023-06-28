#ifndef LINE_H
#define LINE_H
#include "graphobj.h"

class Line :  public GraphObj
{

public:
    Line(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, firstPunkt_, lastPunkt_){}
    void malen(QPainter* objkt, bool  deko_ = false) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint punkt) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_, bool) override;
    void calcBBox(QPoint &min, QPoint &max) const override;


};

#endif // LINE_H
