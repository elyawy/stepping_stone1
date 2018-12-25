//
// Created by elyawy on 12/25/18.
//

#include "redefineVarCommand.h"

void redefineVarCommand::execute() {
    std::string var = mapH.getParsed()->back();
    if (mapH.getparseQueue()->front() == "="){
        jump();
        double x = mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
        mapH.getsymblTable()->at(var) = x;
        jump();
    }
}

void redefineVarCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string redefineVarCommand::stringify() {
    return std::__cxx11::string();
}

void redefineVarCommand::jump() {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
}
