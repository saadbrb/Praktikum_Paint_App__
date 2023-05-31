#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "graphobj.h"


class Circle : public GraphObj {
private:
    int radius;

public:
    Circle(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_, bool innere_mal_frage_):
        GraphObj(color_, firstPunkt_, lastPunkt_, innere_mal_frage_){

        double a= abs(firstPunkt_.rx()-lastPunkt_.rx());
        double b = abs(firstPunkt_.ry()-lastPunkt_.ry());
        double c = sqrt(a*a + b*b);
        radius = (int) c;
    }


    void malen(QPainter *painter) override;

    bool isKlein() override;

    void addPunkt(QPoint punkt_) override;



};


#endif // CIRCLE_H
