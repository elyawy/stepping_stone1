//
// Created by elyawy on 12/22/18.
//

#include "varExpression.h"


varExpression::varExpression(std::string &var) {
    this->num = var;
}

double varExpression::calculate(mapHandler &mapH) {
    return mapH.getsymblTable()->at(num);
}

