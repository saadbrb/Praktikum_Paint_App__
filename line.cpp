#include "line.h"
#include<cmath>


void Line::malen(QPainter* objkt, bool frage) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    objkt->drawLine(firstPunkt, lastPunkt);
    if(frage){
        calcBBox(min, max);
        objkt->setPen(QPen(Qt::red, 2, Qt::DashLine));
        objkt->setBrush(Qt::NoBrush);
        objkt->drawRect(QRect(min, max));
    }
}


void Line::setColor(QColor color_, bool innenMAl_) {
    color = color_;
    innenMAl = innenMAl_;
}
void Line::calcBBox(QPoint &min, QPoint &max) const  {
    int minX = std::min(firstPunkt.x(), lastPunkt.x());
    int minY = std::min(firstPunkt.y(), lastPunkt.y());
    int maxX = std::max(firstPunkt.x(), lastPunkt.x());
    int maxY = std::max(firstPunkt.y(), lastPunkt.y());

    min.setX(minX);
    min.setY(minY);
    max.setX(maxX);
    max.setY(maxY);
}


void Line::addPunkt(QPoint punkt) {
    //Kein Code notwendig

}
void Line::remov(QPoint punkt) {
    QPoint tpr;
    tpr.setX(punkt.rx() - firstPunkt.rx());
    tpr.setY(punkt.ry() - firstPunkt.ry());


    firstPunkt.setX(firstPunkt.rx() + tpr.rx());
    firstPunkt.setY(firstPunkt.ry() + tpr.ry());
    lastPunkt.setX(lastPunkt.rx() + tpr.rx());
    lastPunkt.setY(lastPunkt.ry() + tpr.ry());
}
bool Line::isSmall() {
    return (abs(firstPunkt.rx() - lastPunkt.rx()) + abs(firstPunkt.ry()-lastPunkt.ry())) <2;

}
bool Line::insideTest(QPoint punkt){
    // Calculate the distances from the point to the endpoints of the line
    double d1 = std::hypot(punkt.x() - firstPunkt.x(), punkt.y() - firstPunkt.y());
    double d2 = std::hypot(punkt.x() - lastPunkt.x(), punkt.y() - lastPunkt.y());

    // Calculate the length of the line
    double lineLength = std::hypot(firstPunkt.x() - lastPunkt.x(), firstPunkt.y() - lastPunkt.y());

    // Define a tolerance (this might need to be adjusted based on  specific use case)
    const double tolerance = 1.0;

    // The point is on (or very close to) the line if the sum of d1 and d2 is equal to the line length within the tolerance
    return std::abs(d1 + d2 - lineLength) < tolerance;
}
