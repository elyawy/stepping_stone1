//
// Created by elyawy on 12/16/18.
//

#include "DefineVarCommand.h"

void DefineVarCommand::execute(std::vector<std::string>::iterator &iter) {
iter++;
std::string a = (*iter);
iter++;
if ((*iter) == "=") {
    iter++;
    double b = stoi(*iter);
    mapH.getsymblTable()->emplace(a, b);
//    iter++;
//    if ((*iter) == "bind") {
//        iter++;
//    }
}

}

void DefineVarCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}


DefineVarCommand::~DefineVarCommand() = default;
