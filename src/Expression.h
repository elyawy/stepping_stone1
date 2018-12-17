//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_EXPRESSION_H
#define STEPPING_STONE1_EXPRESSION_H

#include <string>
#include <vector>

class Expression {
public:
    virtual double calculate(std::vector<std::string>::iterator &iter) = 0;
    virtual ~Expression(){};
};


#endif //STEPPING_STONE1_EXPRESSION_H
