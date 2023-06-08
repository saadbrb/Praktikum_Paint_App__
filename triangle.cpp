#include "triangle.h"

void Triangle::malen(QPainter* objkt) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    // Erstelle ein QPolygonF Objekt
    QPolygonF polygon;

    //  Punkte zum Polygon hinzuguen
    for (const QPoint& punkt : punkten) {
        polygon << punkt;
    }
    if(innenMAl){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }

    objkt->drawPolygon(polygon);

}

void Triangle::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}

void Triangle::addPunkt(QPoint punkt) {

    punkten.push_back(punkt);


}
void Triangle::remov(QPoint punkt) {
    QPoint tpr;
    tpr.setX(punkt.rx() - firstPunkt.rx());
    tpr.setY(punkt.ry() - firstPunkt.ry());

    for(QPoint& p : punkten){
        p.setX(p.rx() + tpr.rx());
        p.setY(p.ry() + tpr.ry());
    }

    firstPunkt = punkt;
}

bool Triangle::isSmall() {
    return  true;

}
bool Triangle::insideTest(QPoint punkt) {
    QPolygonF polygon;
    for (const QPoint& punkt : punkten) {
        polygon << punkt;
    }
    return polygon.containsPoint(punkt, Qt::OddEvenFill);
}




