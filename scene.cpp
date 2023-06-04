#include "scene.h"

void Scene::addObjkt(GraphObj* objkt){
    objketen.push_back(objkt);
    std::cout<<"Objekt wurde erfolgreich reingefuegt!\n";
    QPoint a;
    a=objkt->getFirstPunkt();
    QPoint b;
    b=objkt->getLastPunkt();
    std::cout<<"Sein firstpunkt x ist : "<<a.rx()<<" und y ist : "<<a.ry() <<"\n";

    std::cout<<"Sein lastpunkt x ist : "<<b.rx()<<" und y ist : "<<b.ry() <<"\n";
}

void Scene::deleteItem(QPoint punkt){
    if(objketen.size() > 0){
        for(auto it = objketen.begin(); it != objketen.end();){
            if((*it)->insideTest(punkt)){
                it = objketen.erase(it);
            } else {
                ++it;
            }
        }
    }

    else {
        std::cout<<"Box leer!\n";
    }

}




void Scene::setInnenColor(QPoint punkt, QColor color){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            if(objketen[i]->insideTest(punkt)){
                objketen[i]->setColor(color);
            }
        }
    }
    else {
        std::cout<<"Box leer!\n";
    }

}

void Scene::alleMalne(QPainter* objkt){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            objketen[i]->malen(objkt);
        }

    }

}
void Scene::deleteAllObjkts(){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            delete objketen[i];
        }
        objketen.clear();
    }
    else {
        std::cout<<"Es gibt keine Element zum Löschen!\n";
    }
}
