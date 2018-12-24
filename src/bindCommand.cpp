//
// Created by elyawy on 12/18/18.
//

#include "bindCommand.h"


void bindCommand::execute() {

    }


void bindCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string bindCommand::stringify() {
    return std::__cxx11::string();
}

bindCommand::~bindCommand() = default;
