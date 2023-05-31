#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include "graphobj.h"

class Rectangle : public GraphObj {

private:

    int width;
    int height;
    int x,y;

public:
    Rectangle(QColor color_, QPoint firstPunkt_, QPoint lastPunkt_, bool innere_mal_frage_):
        GraphObj(color_, firstPunkt_, lastPunkt_, innere_mal_frage_){
        x = firstPunkt.rx();
        y = firstPunkt.ry();
        width = lastPunkt.rx()-firstPunkt.rx();
        height =lastPunkt.ry()-firstPunkt.ry();

    }


    void malen(QPainter *painter) override;

    bool isKlein() override;

    void addPunkt(QPoint punkt_) override;



};


#endif // RECTANGLE_H
