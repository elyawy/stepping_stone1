//
// Created by ziv_t on 12/15/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {

}

Plus::Plus(double left, Expression *right) : BinaryExpression(left, right) {

}

Plus::Plus(Expression *left, double right) : BinaryExpression(left, right) {

}

Plus::Plus(double left, double right) : BinaryExpression(left, right) {

}

double Plus::calculate(mapHandler &mapH) {
    return this->getLeftExp()->calculate(mapH) + this->getRightExp()->calculate(mapH);
}

Plus::Plus(std::string &left, std::string &right) : BinaryExpression(left, right) {

}

Plus::Plus(Expression *left, std::string &right) : BinaryExpression(left, right) {

}

std::string Plus::stringify() {
    return getLeftExp()->stringify() + " + " + getRightExp()->stringify();
}






