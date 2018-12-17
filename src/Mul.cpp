//
// Created by ziv_t on 12/16/18.
//

#include "Mul.h"

Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Mul::Mul(double left, Expression *right) : BinaryExpression(left, right) {}

Mul::Mul(Expression *left, double right) : BinaryExpression(left, right) {}

Mul::Mul(double left, double right) : BinaryExpression(left, right) {}

double Mul::calculate(std::vector<std::string>::iterator &iter) {
    return this->getLeftExp()->calculate(iter) * this->getRightExp()->calculate(iter);
}
