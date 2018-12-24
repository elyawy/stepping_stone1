//
// Created by elyawy on 12/23/18.
//

#include "booleanExpression.h"

booleanExpression::booleanExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {

}

double booleanExpression::calculate(mapHandler &mapH) {
    if (compare == "<=") return (this->getLeftExp()->calculate(mapH) <= this->getRightExp()->calculate(mapH));
    if (compare == ">=") return (this->getLeftExp()->calculate(mapH) >= this->getRightExp()->calculate(mapH));
    if (compare == "==") return (this->getLeftExp()->calculate(mapH) == this->getRightExp()->calculate(mapH));
    if (compare == ">") return (this->getLeftExp()->calculate(mapH) > this->getRightExp()->calculate(mapH));
    if (compare == "<") return (this->getLeftExp()->calculate(mapH) < this->getRightExp()->calculate(mapH));

    return 0;
}

void booleanExpression::setcomparator(std::string &comp) {
 compare = comp;
}

booleanExpression::~booleanExpression() {

}

std::string booleanExpression::stringify() {
    return getLeftExp()->stringify() + compare + getRightExp()->stringify();
}
