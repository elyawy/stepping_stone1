//
// Created by elyawy on 12/22/18.
//

#include "varExpression.h"


varExpression::varExpression(std::string &var) {
    this->num = var;
}

double varExpression::calculate(mapHandler &mapH) {
    mapH.getExecuted()->push(mapH.getToExecute()->front());
    mapH.getToExecute()->pop();
    if (!mapH.getToExecute()->empty()) {
        mapH.getExpressions()->at(mapH.getToExecute()->front())->calculate(mapH);
    }
    if (mapH.getsymblTable()->count(num) > 0 && mapH.getTokens()->count("var") == 0
        && mapH.getTokens()->count("print") == 0){
        double x = mapH.getExpressions()->at("evaluate")->calculate(mapH);
        mapH.getsymblTable()->at(num) = x;
    }
    if (mapH.getsymblTable()->count(num) == 0 && mapH.getExpressions()->count("command") > 0) {
        mapH.getsymblTable()->emplace(num, 0);
        if (mapH.getExpressions()->count("evaluate")>0){
        double x = mapH.getExpressions()->at("evaluate")->calculate(mapH);
        mapH.getsymblTable()->at(num) = x;
        }
    } else return mapH.getsymblTable()->at(num);
}

std::string varExpression::stringify() {
    return num;
}


