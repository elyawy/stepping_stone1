//
// Created by elyawy on 12/23/18.
//

#ifndef STEPPING_STONE1_BOOLEANEXPRESSION_H
#define STEPPING_STONE1_BOOLEANEXPRESSION_H


#include "BinaryExpression.h"

class booleanExpression: public BinaryExpression {
    std::string compare;
public:
    booleanExpression(Expression *left, Expression *right);
    void setcomparator(std::string &comp);
    double calculate(mapHandler &mapH) override;

    std::string stringify() override;

    ~booleanExpression() override;

};



#endif //STEPPING_STONE1_BOOLEANEXPRESSION_H
