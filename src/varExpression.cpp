//
// Created by elyawy on 12/22/18.
//

#include "varExpression.h"


varExpression::varExpression(std::string &var) {
    this->num = var;
}

double varExpression::calculate(mapHandler &mapH) {
    if (mapH.getsymblTable()->count(num) > 0) {
        return mapH.getsymblTable()->at(num);
    } else throw "variable not initialized";
}

std::string varExpression::stringify() {
    return num;
}

void varExpression::jump(mapHandler &mapH) {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
}

