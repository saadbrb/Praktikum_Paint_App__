#include "polyline.h"


void Polyline::addPunkt(QPoint punkt) {
    punkten.push_back(punkt);
}
void Polyline::malen(QPainter *painter) {
    painter->setPen(QPen(color,2,Qt::SolidLine));
    painter->drawPolyline(punkten);
}
bool Polyline::isKlein() {

    return false;
}
