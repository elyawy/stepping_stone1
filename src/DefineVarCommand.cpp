//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "DefineVarCommand.h"

void DefineVarCommand::execute(std::vector<std::string>::iterator &iter) {
iter++;
mapH.getsymblTable()->emplace(*iter, 0);
}

void DefineVarCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}


DefineVarCommand::~DefineVarCommand() = default;
