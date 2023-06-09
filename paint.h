#ifndef PAINT_H
#define PAINT_H
#include <QWidget>

class QPushButton;
class QComboBox;
class QLabel;
class QCheckBox;
class Canvas;

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = 0);
    ~Paint();

private slots:
    void clearBtnPressed();
    void deleteBtnPressed();
    void colorBtnPressed();
    void primModeChanged();
    void showOutlineOnly(bool);
    void showAllBBoxes(bool);

private:
    Canvas *viewport;

    QPushButton *btnClearCanvas;
    QComboBox *cobPrimModes;
    QLabel *lblPrimModes;
    QPushButton *btnDeleteObj;
    QPushButton *btnChangeCol;
    QCheckBox *cbOutline;
    QCheckBox *allBox;
};

#endif // PAINT_H
