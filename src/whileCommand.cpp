//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "whileCommand.h"

void whileCommand::execute() {
    if (commandList.empty()) {
        loopInitializer();
    }

    while (checkCondition()){
        loopStarter();
    }
    jump();
}

void whileCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string whileCommand::stringify() {
    return std::__cxx11::string();
}

