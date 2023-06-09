#include "polygone.h"

void Polygone::malen(QPainter* objkt, bool frage) {
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
    if(frage){
        calcBBox(min, max);
        objkt->setPen(QPen(Qt::red, 2, Qt::DashLine));
        objkt->setBrush(Qt::NoBrush);
        objkt->drawRect(QRect(min, max));
    }

}
void Polygone::calcBBox(QPoint &min, QPoint &max) const  {
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



void Polygone::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}

void Polygone::addPunkt(QPoint punkt) {
    punkten.push_back(punkt);

}
void Polygone::remov(QPoint punkt) {
    QPoint tpr;
    tpr.setX(punkt.rx() - firstPunkt.rx());
    tpr.setY(punkt.ry() - firstPunkt.ry());

    for(QPoint& p : punkten){
        p.setX(p.rx() + tpr.rx());
        p.setY(p.ry() + tpr.ry());
    }

    // Aktualisieren von dem 'firstPunkt' auf die neue Position
    firstPunkt = punkt;
}

bool Polygone::isSmall() {
    return  true;

}
bool Polygone::insideTest(QPoint punkt) {
    QPolygonF polygon;
    for (const QPoint& punkt : punkten) {
        polygon << punkt;
    }
    return polygon.containsPoint(punkt, Qt::OddEvenFill);
}


bool Polygone::isNear(const QPoint& a) {
    int dx = a.x() - firstPunkt.rx();
    int dy = a.y() - firstPunkt.ry();
    return std::sqrt(dx * dx + dy * dy) <= 10;
}

