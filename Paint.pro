# http://doc.qt.io/qt-5/qmake-variable-reference.html
CONFIG += console
QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
#LIBS += 
INCLUDEPATH += .

HEADERS += paint.h \
           canvas.h \
           circle.h \
           graphobj.h \
           line.h \
           polyline.h \
           rectangle.h \
           scene.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           graphobj.cpp \
           line.cpp \
           main.cpp \
           polyline.cpp \
           rectangle.cpp \
           scene.cpp
