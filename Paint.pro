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
           polygone.h \
           polyline.h \
           rectangle.h \
           scene.h \
           triangle.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           graphobj.cpp \
           line.cpp \
           main.cpp \
           polygone.cpp \
           polyline.cpp \
           rectangle.cpp \
           scene.cpp \
           triangle.cpp
