//
// Created by ziv_t on 12/16/18.
//

#include <stdexcept>
#include "Div.h"

Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Div::Div(double left, Expression *right) : BinaryExpression(left, right) {}

Div::Div(Expression *left, double right) : BinaryExpression(left, right){}

Div::Div(double left, double right) : BinaryExpression(left, right) {}

double Div::calculate(mapHandler &mapH) {
    if (this->getRightExp()->calculate(mapH) == 0) {
        throw std::domain_error("Cant Divide by 0");
    }
    return this->getLeftExp()->calculate(mapH) / this->getRightExp()->calculate(mapH);
}

Div::Div(std::string &left, std::string &right) : BinaryExpression(left, right) {

}

Div::Div(Expression *left, std::string &right) : BinaryExpression(left, right) {

}

std::string Div::stringify() {
    return getLeftExp()->stringify() + " / " + getRightExp()->stringify();
}
