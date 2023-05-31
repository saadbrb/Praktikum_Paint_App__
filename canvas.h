#ifndef CANVAS_H
#define CANVAS_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include "scene.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "polyline.h"
#include "graphobj.h"

class Canvas : public QFrame
{
    Q_OBJECT

public:
    enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
    };

    Canvas(QWidget *parent = 0);
    ~Canvas();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void clearCanvas();
    void setPrimitiveMode(int mode);
    void setInnerFrage(bool farge);
    void setFarbe(QColor color_);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool dragging;
    PrimitiveMode type;
    QColor color;
    QPoint firstPunkt;
    QPoint lastPunkt;
    bool innereFrage;
    Scene scene;
    GraphObj* tmprGraphOb_;
};


#endif // CANVAS_H
