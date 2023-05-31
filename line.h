#ifndef LINE_H
#define LINE_H
#include "graphobj.h"

class Line :  public GraphObj
{

public:

    Line(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_):
        GraphObj(color_, firstPunkt_, lastPunkt_){
    }


    void malen(QPainter *painter) override;

    bool isKlein() override;
    void addPunkt(QPoint punkt_) override;


};

#endif // LINE_H
