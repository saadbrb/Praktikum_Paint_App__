#include "scene.h"

void Scene::addObjkt(GraphObj* objkt_){

    objketen.push_back(new BBoxDecorator(objkt_, isSchowBox));
    std::cout<<"Objekt wurde erfolgreich reingefuegt!\n";
    QPoint a;
    a=objkt_->getFirstPunkt();
    QPoint b;
    b=objkt_->getLastPunkt();
    std::cout<<"Sein firstpunkt x ist : "<<a.rx()<<" und y ist : "<<a.ry() <<"\n";

    std::cout<<"Sein lastpunkt x ist : "<<b.rx()<<" und y ist : "<<b.ry() <<"\n";
}
void Scene::deleteItem(QPoint punkt) {
    // Erst prüfen, ob die Liste leer ist
    if(objketen.empty()) {
        std::cout << "Die Liste ist leer!\n";
        return;
    }

    // Durch die Liste gehen und prüfen, ob der Punkt in einem Objekt liegt
    for (int i = 0; i < objketen.size(); ++i) {
        if (objketen[i]->insideTest(punkt)) {
            std::cout<<"Es gibt jetzt size : "<<objketen.size()<<"\n";
            // Wenn der Punkt innerhalb des Objekts liegt, das Objekt löschen
            delete objketen[i]; // Zuerst Speicher freigeben
            objketen.erase(objketen.begin() + i); // Dann das Element aus der Liste entfernen

            std::cout<<"Es gibt jetzt size : "<<objketen.size()<<"\n";

            return;
        }
    }
}


void Scene::setPosition(QPoint punkt, int i){


    objketen[i]->remov(punkt);

}

int Scene::isSelectes(QPoint punkt){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            if(objketen[i]->insideTest(punkt)){
                return i;
            }
        }
        return -1;
    }
    else {
        std::cout<<"Box leer!\n";
        return -1;
    }
}





void Scene::setInnenColor(QPoint punkt, QColor color, bool innenFrage){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            if(objketen[i]->insideTest(punkt)){
                objketen[i]->setColor(color, innenFrage);
            }
        }
    }
    else {
        std::cout<<"Box leer!\n";
    }

}

void Scene::alleMalne(QPainter* objkt, bool ischoBox){
    if(objketen.size() > 0){
        for(size_t i=0; i<objketen.size(); i++){
            objketen[i]->malen(objkt, isSchowBox);
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
        std::cout<<"Es gibt keine Element zum Loeschen!\n";
    }

}

void Scene::setSchowbox(bool frage){
    isSchowBox = frage;
}
