#include "triangle.h"

void Triangle::malen(QPainter* objkt, bool deko) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    QPolygonF polygon;

    for (const QPoint& punkt : punkten) {
        polygon << punkt;
    }
    if(innenMAl){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }

    // Zeichnen  des Polygons
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


void Triangle::calcBBox(QPoint &min, QPoint &max) const  {
    int minX = punkten[0].x(), minY = punkten[0].y();
    int maxX = minX, maxY = minY;

    for (const QPoint &p : punkten) {
        minX = std::min(minX, p.x());
        minY = std::min(minY, p.y());
        maxX = std::max(maxX, p.x());
        maxY = std::max(maxY, p.y());
    }

    min.setX(minX);
    min.setY(minY);
    max.setX(maxX);
    max.setY(maxY);

}


