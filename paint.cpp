#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>
#include <QCheckBox>
#include <QDebug>
#include "paint.h"
#include "canvas.h"

enum InteractionMode { CREAT, DEL, COL, TRAFO };

/** c'tor */
Paint::Paint(QWidget *parent)
    : QWidget(parent)
{
    // instantiate Canvas and button
    viewport = new Canvas();

    btnClearCanvas = new QPushButton("&Clear Canvas");

    cobPrimModes = new QComboBox();
    cobPrimModes->addItem(tr("None"), Canvas::NONE);
    cobPrimModes->addItem(tr("Line"), Canvas::LINE);
    cobPrimModes->addItem(tr("Freehand"), Canvas::FREE_HAND);
    cobPrimModes->addItem(tr("Circle"), Canvas::CIRCLE);
    cobPrimModes->addItem(tr("Rectangle"), Canvas::RECTANGLE);
    //cobPrimModes->addItem(tr("Triangle"), Canvas::TRIANGLE);
    cobPrimModes->addItem(tr("Polygon"), Canvas::POLYGON);

    lblPrimModes = new QLabel("Primitive Mode");
    lblPrimModes->setBuddy(cobPrimModes);

//    btnDeleteObj = new QPushButton("&Delete Selected");
//    btnDeleteObj->setDisabled(true);
    btnChangeCol = new QPushButton("C&hange Color");

    cbOutline = new QCheckBox("Show Only &Outline", this);

    // create layout and add gui elements to it
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(viewport,       0, 0, 1, 4);
    mainLayout->addWidget(btnChangeCol,   1, 0);
    mainLayout->addWidget(cbOutline,      1, 1, Qt::AlignLeft);
    mainLayout->addWidget(lblPrimModes,   1, 2, Qt::AlignRight);
    mainLayout->addWidget(cobPrimModes,   1, 3);
    mainLayout->addWidget(btnDeleteObj,   2, 0);
    mainLayout->addWidget(btnClearCanvas, 2, 3);

    // add layout to this widget instance
    setLayout(mainLayout);

    // connect button click event to clear canvas handler
    connect(btnClearCanvas, SIGNAL(clicked()),
            this, SLOT(clearBtnPressed()));
    // connect button click event to delete selected object handler
    connect(btnDeleteObj, SIGNAL(clicked()),
            this, SLOT(deleteBtnPressed()));
    // connect button click event to color chooser handler
    connect(btnChangeCol, SIGNAL(clicked()),
            this, SLOT(colorBtnPressed()));
    // connect list view to primitive changed event handler
    connect(cobPrimModes, SIGNAL(activated(int)),
            this, SLOT(primModeChanged()));
    // connect checkbox to toggle outline event handler
    connect(cbOutline, SIGNAL(toggled(bool)),
            this, SLOT(showOutlineOnly(bool)));


    // Create a QGroupBox for the radio buttons
    QGroupBox *groupBox = new QGroupBox("Interaction Modes");
    QVBoxLayout *vbox = new QVBoxLayout;

    QRadioButton *button1 = new QRadioButton("Create");
    QRadioButton *button2 = new QRadioButton("Delete");
    QRadioButton *button3 = new QRadioButton("Color");
    QRadioButton *button4 = new QRadioButton("Transform");

    vbox->addWidget(button1);
    vbox->addWidget(button2);
    vbox->addWidget(button3);
    vbox->addWidget(button4);

    groupBox->setLayout(vbox);

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(button1, CREAT);
    buttonGroup->addButton(button2, DEL);
    buttonGroup->addButton(button3, COL);
    buttonGroup->addButton(button4, TRAFO);

    QObject::connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
                        [this](int id){ this->viewport->setInteractionMode(id); });

    // Add the group box to the layout
    mainLayout->addWidget(groupBox, 3, 0, 1, 4);
}

/** d'tor */
Paint::~Paint()
{
}

/** method for handling button clicked event */
void Paint::clearBtnPressed()
{
    viewport->clearCanvas();

    // force redraw
    update();
    qDebug() << "Clear image called";
}

void Paint::deleteBtnPressed()
{
    // Implementation requires inside test for all objects for selection
    qDebug() << "Next action: delete selected item (NYI)";
}

void Paint::colorBtnPressed()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if (color.isValid()) {
        qDebug() << "Color Choosen : " << color.name();
        //viewport->setObjColor(color);
        viewport->setColor(color);
    }
}

void Paint::showOutlineOnly(bool outline)
{
    qDebug() << "Only show outline: " << outline;
    //viewport->setFillMode(!outline);
    viewport->setInnenFrage(!outline);
}

void Paint::primModeChanged()
{
    int mode = cobPrimModes->itemData(
                cobPrimModes->currentIndex(), Qt::UserRole).toInt();
    viewport->setPrimitiveMode(mode);
    qDebug() << "Primitive Mode changed to " << mode;
}
