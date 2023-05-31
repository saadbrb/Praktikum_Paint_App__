#ifndef SCENE_H
#define SCENE_H
#include <QFrame>
#include <QtGui>
#include <QtCore>
#include<iostream>
#include<vector>
#include"graphobj.h"

class GraphObj;

class Scene {
private:
    std::vector<GraphObj*> graphObjekten;

public:
    Scene(){

    }

    void displayAllEllement(QPainter *painter);
    void deletAllEllement();
    void addElement(GraphObj* objkt_);
    ~Scene(){
        for(GraphObj* A : graphObjekten){
            delete A;
        }

    }
};

#endif // SCENE_H
