//
// Created by ziv_t on 12/14/18.
//

#include "Number.h"

Number::Number(double number) {
    this->num = number;
}

double Number::calculate(mapHandler &mapH) {
    return this->num;
}

double Number::getNum() {
    return this->num;
}

std::string Number::stringify() {
    return std::to_string(num);
}


