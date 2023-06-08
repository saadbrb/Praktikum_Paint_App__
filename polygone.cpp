#include "polygone.h"

void Polygone::malen(QPainter* objkt) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    // Erstelle ein QPolygonF Objekt
    QPolygonF polygon;

    // Füge Punkte zum Polygon hinzu
    for (const QPoint& punkt : punkten) {
        polygon << punkt;
    }
    if(innenMAl || mussGemalt){
        objkt->setBrush(color);
    } else{
        objkt->setBrush(Qt::NoBrush);
    }

    // Zeichne das Polygon
    objkt->drawPolygon(polygon);

}


void Polygone::setColor(QColor color_) {
    color = color_;
    mussGemalt = true;


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

    // Aktualisiere den 'firstPunkt' auf die neue Position
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

