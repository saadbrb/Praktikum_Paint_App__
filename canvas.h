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
#include "scene.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "polyline.h"
#include "graphobj.h"
#include "polygone.h"

class Canvas : public QFrame
{
    Q_OBJECT

public:
    enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
    };

    enum InteractionMode { CREAT, DEL, COL, TRAFO }; // Hier ist die Aufzählung

    Canvas(QWidget *parent = 0);
    ~Canvas(){
        delete objkt;
        delete polyObjkt;
    }

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void clearCanvas();
    void setPrimitiveMode(int mode);
    void setColor(QColor color_);
    void createRadioButtons();

    void setInnenFrage(bool frage);
    void interactionModeChanged(int id);
    void setInteractionMode(int mode_);



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
    bool innenFrage;
    Scene scene;
    GraphObj* objkt;
    Polygone* polyObjkt;
    QButtonGroup *buttonGroup;
    QGroupBox *groupBox;
    InteractionMode mode;
    QPoint innenTestPunkt;
    int checkPress =0;
    QPoint tPunkt;
    bool selected = false;
    int i = -1;


};


#endif // CANVAS_H
