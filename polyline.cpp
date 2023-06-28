#include<cmath>
#include "polyline.h"


void Polyline::malen(QPainter* objkt, bool deko) {

    objkt->setPen(QPen(color,2,Qt::SolidLine));
    objkt->drawPolyline(punkten);



}
void Polyline::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}

void Polyline::addPunkt(QPoint punkt) {
    if(punkten.size() == 1){
        firstPunkt = punkt;
    }
    punkten.push_back(punkt);
}
void Polyline::remov(QPoint newLocation) {
    QPoint offset;
    offset.setX(newLocation.rx() - firstPunkt.rx());
    offset.setY(newLocation.ry() - firstPunkt.ry());

    for(size_t i=0; i < punkten.size(); i++){
        punkten[i].setX(punkten[i].rx() + offset.rx());
        punkten[i].setY(punkten[i].ry() + offset.ry());
    }

    // Aktualisieren Sie firstPunkt zur neuen Position
    firstPunkt = newLocation;
}
bool Polyline::isSmall() {

    return false;
}


bool Polyline::insideTest(QPoint punkt) {
    // Define a tolerance (this might need to be adjusted based on your specific use case)
    const double tolerance = 1.0;

    for (size_t i = 0; i < punkten.size() - 1; i++) {
        // Calculate the distances from the point to the endpoints of the line segment
        double d1 = std::hypot(punkt.x() - punkten[i].x(), punkt.y() - punkten[i].y());
        double d2 = std::hypot(punkt.x() - punkten[i+1].x(), punkt.y() - punkten[i+1].y());

        // Calculate the length of the line segment
        double lineLength = std::hypot(punkten[i].x() - punkten[i+1].x(), punkten[i].y() - punkten[i+1].y());

        // The point is on (or very close to) the line if the sum of d1 and d2 is equal to the line length within the tolerance
        if (std::abs(d1 + d2 - lineLength) < tolerance) {
            return true;
        }
    }

    return false;
}
void Polyline::calcBBox(QPoint &min, QPoint &max) const  {
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

