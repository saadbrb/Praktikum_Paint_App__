#ifndef SCENE_H
#define SCENE_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include<iostream>
#include<vector>
#include"graphobj.h"



class Scene {


public:
    void addObjkt(GraphObj* objkt);
    void alleMalne(QPainter* objkt);
    void deleteAllObjkts();
    void setInnenColor(QPoint punkt, QColor color, bool innenFrage);
    void deleteItem(QPoint punkt);
    int isSelectes(QPoint punkt);
    void setPosition(QPoint punkt, int i);
    ~ Scene(){
        if(objketen.size() > 0)
            for(size_t i=0; i<objketen.size(); i++){
                delete objketen[i];
            }

    }
private:
    std::vector<GraphObj*> objketen;

};

#endif // SCENE_H
