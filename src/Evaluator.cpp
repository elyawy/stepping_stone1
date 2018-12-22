//
// Created by elyawy on 12/21/18.
//

#include <stack>
#include "Evaluator.h"
#include "Number.h"
#include "string"
#include "Plus.h"

Expression *Evaluator::analizer(std::string &express) {
    int i = 0;
    std::string temp;
//    while (i < express.size()){
//        temp+= express[i];
////      if (express[i] == '<' || '>' || '='){
////
////        // booleanExpression creator.
////
////        // return boolean expression.
////       }
//        i++;
//    }
    shuntingYard(express);

}

Expression *Evaluator::shuntingYard(std::string &express1) {
    int i = 0;
    std::vector<std::string> express;
    for (int j = 0; j < express1.size(); j++) {
        std::string temp;
        if (express1[j] == ' ') continue;
        while (isalpha(express1[j])){
            temp += express1[j];
            j++;
            if (!isalpha(express1[j])) {express.push_back(temp);temp = "";break;}
        }
        if (express1[j] == ' ') continue;
        if (!isdigit(express1[j]) && j < express1.size()) {
            temp += express1[j];
            express.push_back(temp);
            continue;}
        while (isdigit(express1[j])){
            temp += express1[j];
            j++;
            if (!isdigit(express1[j])) {express.push_back(temp); j--;break;}
        }
    }

    std::stack<std::string> stack;
    std::queue<std::string> queue;

    // shunting yard algorithm.
    while (i < express.size()){
        if (express[i] == " ") {i++;
            continue;}
        if (isNum(express[i]) == 1) {queue.push(express[i]); i++;}
        if (isOperator(express[i])) {
            if (!stack.empty()){
                while(!stack.empty()) {
                    if (operatorValue(stack.top()) > operatorValue(express[i]) && isOperator(express[i])){
                        queue.push(stack.top());
                        stack.pop();
                    } else break;
                }
                stack.push(express[i]);
                i++;
            } else {
                stack.push(express[i]);
                i++;
            }
        }
        if (express[i] == "("){
            stack.push(express[i]);
            i++;
        }
        if (express[i] == ")"){
            while (!stack.empty()){
                if (stack.top() == "("){
                    stack.pop();
                } else {
                    queue.push(stack.top());
                    stack.pop();
                }
            }
            i++;
        }
    }
    while (!stack.empty()){
        queue.push(stack.top());
        stack.pop();
    }
    express.clear();
    while (!queue.empty()) {
        if (queue.front() == "") {queue.pop() ;continue;}
        express.push_back(queue.front());
        queue.pop();
    }
    return expressionBuilder(express);
}

int Evaluator::operatorValue(std::string &a) {
    if (a == "+") return 10;
    if (a == "-") return 10;
    if (a == "*") return 20;
    if (a == "/") return 20;

    return 0;
}

bool Evaluator::isOperator(std::string &a) {
    if (a == "(" || a == ")") return false;
    return a == "+" || "-" || "/" || "*";

}

Expression *Evaluator::expressionBuilder(std::vector<std::string> &queue) {
    if (queue.size() == 1) {
        if (isdigit(queue.back().at(0))){
            double x = stoi(queue.back());
            return new Number(x);
        }
    }



}

bool Evaluator::isNum(std::string &a) {
    return isdigit(a[0]) || isalpha(a[0]);

}


