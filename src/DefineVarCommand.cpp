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

void DefineVarCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}


DefineVarCommand::~DefineVarCommand() = default;
