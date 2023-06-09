#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H
#include <graphobj.h>

class BBoxDecorator : public GraphObj
{
private:

    GraphObj* decoratedObj;

public:
    BBoxDecorator(GraphObj* obj) : decoratedObj(obj) {}
    void malen(QPainter* objkt, bool) override ;
    void addPunkt(QPoint punkt) override;
    void remov(QPoint punkt) override;
    bool isSmall() override;
    bool insideTest(QPoint punkt) override;
    void setColor(QColor color_, bool) override;
    void calcBBox(QPoint &min, QPoint &max) const override;

};

#endif // BBOXDECORATOR_H
