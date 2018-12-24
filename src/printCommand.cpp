//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"
#include <algorithm>

void printCommand::execute() {
std::cout << mapH.getExpressions()->at(mapH.getToExecute()->front())->calculate(mapH) << std::endl;

}

void printCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string printCommand::stringify() {
    return std::__cxx11::string();
}
