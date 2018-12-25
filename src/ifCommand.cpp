//
// Created by elyawy on 12/25/18.
//

#include "ifCommand.h"

void ifCommand::execute() {
    Command::execute();
}

void ifCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string ifCommand::stringify() {
    return std::__cxx11::string();
}
