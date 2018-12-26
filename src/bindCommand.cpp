//
// Created by elyawy on 12/18/18.
//

#include "bindCommand.h"


void bindCommand::execute() {
    int i = 0;
    std::string var;
    while (i < mapH.getParsed()->size()){
        if (mapH.getTokens()->count(mapH.getParsed()->front()) == VARIABLE){
            var = mapH.getParsed()->front();
        }
        mapH.getParsed()->push(mapH.getParsed()->front());
        mapH.getParsed()->pop();
    }
    if (mapH.getTokens()->at(mapH.getparseQueue()->front()) == QUOTED){
        if (mapH.getvartobindMap()->count(var) > 0) {
            mapH.getvartobindMap()->erase(var);
            mapH.getvartobindMap()->emplace(var, mapH.getparseQueue()->front());
            jump();
        } else {
            mapH.getvartobindMap()->emplace(var, mapH.getparseQueue()->front());
            jump();
        }

    } else {
        if (mapH.getvartobindMap()->count(mapH.getparseQueue()->front()) >0){
            std::string bind = mapH.getvartobindMap()->at(mapH.getparseQueue()->front());
            mapH.getvartobindMap()->emplace(var, bind);
            jump();
        } else {
            jump();
            return;
        }
    }
}


void bindCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string bindCommand::stringify() {
    return std::__cxx11::string();
}



bindCommand::~bindCommand() = default;
