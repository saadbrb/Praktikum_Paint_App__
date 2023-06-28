#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>
#include <QCheckBox>
#include <QDebug>
#include<QAction>
#include<QFile>
#include<QMenu>
#include<QMenuBar>
#include<QFileDialog>
#include "paint.h"
#include "canvas.h"
#include "qapplication.h"

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
    cobPrimModes->addItem(tr("Polygon"), Canvas::POLYGON);
    cobPrimModes->addItem(tr("Triangle"), Canvas::TRIANGLE);

    lblPrimModes = new QLabel("Primitive Mode: ");
    lblPrimModes->setBuddy(cobPrimModes);


    //    btnDeleteObj = new QPushButton("&Delete Selected");
    //    btnDeleteObj->setDisabled(true);
    btnChangeCol = new QPushButton("Set Color");

    cbOutline = new QCheckBox("Show Only &Outline", this);
    allBox = new QCheckBox("Show all BBoxes", this);

    // create layout and add gui elements to it
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(viewport,       0, 0, 1, 4);
    mainLayout->addWidget(lblPrimModes,   3, 2, Qt::AlignRight);
    mainLayout->addWidget(cobPrimModes,   3, 3);
    mainLayout->addWidget(cbOutline,      4, 2);
    mainLayout->addWidget(btnChangeCol,   4, 3);
    mainLayout->addWidget(allBox,      5, 2);
    //  mainLayout->addWidget(btnDeleteObj,   2, 0);
    mainLayout->addWidget(btnClearCanvas, 5, 3);





    // add layout to this widget instance
    setLayout(mainLayout);

    // connect button click event to clear canvas handler
    connect(btnClearCanvas, SIGNAL(clicked()),
            this, SLOT(clearBtnPressed()));
    // connect button click event to delete selected object handler
    //    connect(btnDeleteObj, SIGNAL(clicked()),
    //            this, SLOT(deleteBtnPressed()));
    // connect button click event to color chooser handler
    connect(btnChangeCol, SIGNAL(clicked()),
            this, SLOT(colorBtnPressed()));
    // connect list view to primitive changed event handler
    connect(cobPrimModes, SIGNAL(activated(int)),
            this, SLOT(primModeChanged()));
    // connect checkbox to toggle outline event handler
    connect(cbOutline, SIGNAL(toggled(bool)),
            this, SLOT(showOutlineOnly(bool)));
    connect(allBox, SIGNAL(toggled(bool)),
            this, SLOT(showAllBBoxes(bool)));

    QGroupBox *groupBox = new QGroupBox("Selection Tools");
    QVBoxLayout *vbox = new QVBoxLayout;

    QRadioButton *button1 = new QRadioButton("Create objects");
    QRadioButton *button2 = new QRadioButton("Delete selected");
    QRadioButton *button3 = new QRadioButton("Change color");
    QRadioButton *button4 = new QRadioButton("Move object");

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
    mainLayout->addWidget(groupBox, 3, 0, 3, 2);
    QAction * save = new QAction ("Save &Image");
    QAction* quit = new QAction("&Quit");
    QMenu* fileMenu = new QMenu("File");
    fileMenu->addAction(save);
    fileMenu->addAction(quit);
    QMenuBar* menuBar = new QMenuBar();
    menuBar->addMenu(fileMenu);
    mainLayout->setMenuBar(menuBar);
    connect(save, &QAction::triggered, this, &Paint::saveImage);
    connect(quit, &QAction::triggered, this, &Paint::quitApplication);


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
void Paint::saveImage() {
    // Größe des Viewports ermitteln
    QSize viewportSize = viewport->size();

    // QImage-Objekt erstellen
    QImage image(viewportSize, QImage::Format_RGB32);

    // QPainter-Objekt erstellen, um auf das QImage-Objekt zu zeichnen
    QPainter painter(&image);

    // Den Inhalt des Viewports in das QImage-Objekt zeichnen
    viewport->render(&painter);

    // Speichern des Bildes
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.xpm *.jpg)"));
    if (!fileName.isEmpty())
    {
        image.save(fileName);
    }
}

void Paint::quitApplication() {
    // Code zum Beenden der Anwendung...
    QApplication::quit();
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
    viewport->setInnenFrage(!outline);
}
void Paint::showAllBBoxes(bool box)
{
    qDebug() << "Show All BBoxes: " << box;
    viewport->setAllBox(box);
}

void Paint::primModeChanged()
{
    int mode = cobPrimModes->itemData(
                cobPrimModes->currentIndex(), Qt::UserRole).toInt();
    viewport->setPrimitiveMode(mode);
    qDebug() << "Primitive Mode changed to " << mode;
}
