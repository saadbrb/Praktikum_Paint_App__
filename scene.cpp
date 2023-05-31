#include "scene.h"


void Scene::displayAllEllement(QPainter *painter){
    for(size_t i=0; i<graphObjekten.size(); i++){
        graphObjekten[i]->malen(painter);
    }
}
void Scene::deletAllEllement(){
    if (!graphObjekten.empty()) {
        for (auto element : graphObjekten) {
            delete element;
        }
        graphObjekten.clear();
    } else {
        std::cout << "No Elements to delete!\n";
    }

}
void Scene::addElement(GraphObj* objkt_){
    graphObjekten.push_back(objkt_);

    std::cout<<"New Ellement ist hinzugefuegt!\n";
    std::cout<<"Size ist: "<<graphObjekten.size()<<"\n";
}
