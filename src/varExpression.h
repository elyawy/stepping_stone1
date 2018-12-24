//
// Created by elyawy on 12/22/18.
//

#ifndef STEPPING_STONE1_VAREXPRESSION_H
#define STEPPING_STONE1_VAREXPRESSION_H


#include "Expression.h"


class varExpression: public Expression {
private:
    std::string num;
public:
    explicit varExpression(std::string &var);
    double calculate(mapHandler &mapH) override;

    std::string stringify() override;
};



#endif //STEPPING_STONE1_VAREXPRESSION_H
