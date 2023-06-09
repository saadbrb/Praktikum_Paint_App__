#ifndef CANVAS_H
#define CANVAS_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include <QFrame>
#include <QButtonGroup>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include "graphobj.h"
#include "scene.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "polyline.h"
#include "polygone.h"

class Canvas : public QFrame
{
    Q_OBJECT

public:
    enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, RECTANGLE, POLYGON, TRIANGLE
    };

    enum InteractionMode { CREAT, DEL, COL, TRAFO }; // Hier ist die Aufzählung

    Canvas(QWidget *parent = 0);
    ~Canvas(){
        delete objkt;
        delete polyObjkt;
        delete trglObjkt;
    }

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void clearCanvas();
    void setPrimitiveMode(int mode);
    void setColor(QColor color_);

    void setInnenFrage(bool frage);
    void setAllBox(bool);
    void setInteractionMode(int mode_);



protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);


    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    bool dragging;
    bool allBox;
    PrimitiveMode type;
    QColor color;
    QPoint firstPunkt;
    QPoint lastPunkt;
    bool innenFrage;
    Scene scene;
    GraphObj* objkt;
    Polygone* polyObjkt;
    Triangle* trglObjkt;
    QButtonGroup *buttonGroup;
    QGroupBox *groupBox;
    InteractionMode mode;
    QPoint innenTestPunkt;
    int checkPress =0;
    QPoint tPunkt;
    bool selected = false;
    int i = -1;
    int counter = 0;


};


#endif // CANVAS_H
