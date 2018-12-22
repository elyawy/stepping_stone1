//
// Created by elyawy on 12/22/18.
//

#ifndef STEPPING_STONE1_VAREXPRESSION_H
#define STEPPING_STONE1_VAREXPRESSION_H


#include "Expression.h"

class varExpression: public Expression {
private:
    double num;
public:
    explicit varExpression(std::string number);
    double calculate(mapHandler &mapH) override;
    double getNum();
};



#endif //STEPPING_STONE1_VAREXPRESSION_H
