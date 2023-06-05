#include "line.h"
#include<cmath>
void Line::malen(QPainter* objkt) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    objkt->drawLine(firstPunkt, lastPunkt);

}


void Line::setColor(QColor color_) {
    color = color_;

}
void Line::addPunkt(QPoint punkt) {
    //some code
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
