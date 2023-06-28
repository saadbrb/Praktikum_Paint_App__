#include "bboxdecorator.h"


void BBoxDecorator::calcBBox(QPoint &min, QPoint &max) const {

    decoratedObj->calcBBox(min, max);

}

void BBoxDecorator::malen(QPainter* objkt, bool frage) {

    if(decoratedObj){
        decoratedObj->malen(objkt, frage);
        if(frage){
            calcBBox(min, max);
            objkt->setPen(QPen(Qt::red, 2, Qt::DashLine));
            objkt->setBrush(Qt::NoBrush);
            objkt->drawRect(QRect(min, max));
        }

    }
}


void BBoxDecorator::setColor(QColor color_, bool innenMAl_) {

    decoratedObj->setColor(color_,innenMAl_);

}

void BBoxDecorator::addPunkt(QPoint punkt) {
    decoratedObj->addPunkt(punkt);


}

void BBoxDecorator::remov(QPoint punkt) {
    decoratedObj->remov(punkt);

}
bool BBoxDecorator::isSmall() {

    return decoratedObj->isSmall();

}
bool BBoxDecorator::insideTest(QPoint punkt){
    return decoratedObj->insideTest(punkt);
}
