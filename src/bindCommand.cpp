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


    } else {

    }

}


void bindCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string bindCommand::stringify() {
    return std::__cxx11::string();
}

bindCommand::~bindCommand() = default;
