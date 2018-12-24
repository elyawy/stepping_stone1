//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    mapH.getExpressions()->at("variable")->calculate(mapH);

//iter++;
//mapH.getsymblTable()->emplace(*iter, 0);
}

void DefineVarCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string DefineVarCommand::stringify() {
    return std::__cxx11::string();
}


DefineVarCommand::~DefineVarCommand() = default;
