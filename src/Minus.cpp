//
// Created by ziv_t on 12/16/18.
//

#include "Minus.h"

Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Minus::Minus(double left, Expression *right) : BinaryExpression(left, right) {}

Minus::Minus(Expression *left, double right) : BinaryExpression(left, right) {}

Minus::Minus(double left, double right) : BinaryExpression(left, right) {}

double Minus::calculate(mapHandler &mapH) {
    return this->getLeftExp()->calculate(mapH) - this->getRightExp()->calculate(mapH);
}
