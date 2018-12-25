//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"
#include <algorithm>

void printCommand::execute() {
    if (mapH.getTokens()->at(mapH.getparseQueue()->front()) == QUOTED) {
        mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
    } else {
        double x = mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
        std::cout << x << std::endl;
        mapH.getParsed()->push(mapH.getparseQueue()->front());
        mapH.getparseQueue()->pop();
    }
}

void printCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string printCommand::stringify() {
    return std::__cxx11::string();
}
