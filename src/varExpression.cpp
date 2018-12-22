//
// Created by elyawy on 12/22/18.
//

#include "varExpression.h"


varExpression::varExpression(std::string number) {
    this->num = stoi(number);
}

double varExpression::calculate(mapHandler &mapH) {
    return this->num;
}

double varExpression::getNum() {
    return this->num;
}
