//
// Created by elyawy on 12/21/18.
//

#include <stack>
#include "Evaluator.h"
#include "Number.h"
#include "string"
#include "Plus.h"
#include "varExpression.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "booleanExpression.h"

Expression *Evaluator::analizer(std::string &express) {
    int i = 0;
    std::string left;
    std::string right;

    std::string boolean;
    while (i < express.size()){

      if (express[i] == '<' ||express[i] == '>' ||express[i] == '='){
        boolean += express[i];
        i++;
        if (express[i] == '<' ||express[i] == '>' ||express[i] == '='){
            boolean += express[i];
            i++;
            break;
        } else break;
       }
        left+= express[i];
        i++;
    }
    if (!boolean.empty()) {
        while (i < express.size()) {
            right += express[i];
            i++;
        }
    }
    if (boolean.empty()) return shuntingYard(left);

    if (!boolean.empty()){
        auto boolexp = new booleanExpression(shuntingYard(left), shuntingYard(right));
        boolexp->setcomparator(boolean);
        return boolexp;
    }
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
            if (express1[j] == '.') {temp += express1[j];
                continue;
            }
            if (!isdigit(express1[j]) && !temp.empty()) {
                express.push_back(temp);
                j--;break;}
        }
    }

    std::stack<std::string> stack;
    std::queue<std::string> queue;

    // shunting yard algorithm.
    while (i < express.size()){
        if (express[i].empty()) {i++;continue;}
        if (express[i] == " ") {i++;
            continue;}
        if (isNum(express[i]) == 1) {
            queue.push(express[i]);
            i++;
            if (i >= express.size()) break;
        }
        if (isOperator(express[i])) {
            if (!stack.empty()){
                while(!stack.empty()) {
                    if (operatorValue(stack.top()) >= operatorValue(express[i]) && isOperator(express[i])){
                        queue.push(stack.top());
                        stack.pop();
                    } else break;
                }
                if (i >= express.size()) break;
                stack.push(express[i]);
                i++;
            } else {
                if (i >= express.size()) break;
                stack.push(express[i]);
                i++;
            }
        }
        if (i >= express.size()) break;
        if (express[i] == "("){
            stack.push(express[i]);
            i++;
        }
        if (i >= express.size()) break;
        if (express[i] == ")"){
            while (!stack.empty()){
                if (stack.top() == "("){
                    stack.pop();
                    break;
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
    if(a.empty()) return 0;
    if (a == "+") return 10;
    if (a == "-") return 10;
    if (a == "*") return 20;
    if (a == "/") return 20;

    return 0;
}

bool Evaluator::isOperator(std::string &a) {
    if(a.empty()) return false;
    if (a == "(" || a == ")") return false;
    return a == "+" || "-" || "/" || "*";

}

Expression *Evaluator::expressionBuilder(std::vector<std::string> &queue) {
    if (queue.size() == 1) {
        if (isdigit(queue.back().at(0))){
            double x = stod(queue.back());
            return new Number(x);
        }
        if (isalpha(queue.back().at(0))){
            return new varExpression(queue.back());
        }
    }
    if (queue.back() == "+"){
        return plusBuilder(queue);
    }
    if (queue.back() == "-"){
        return minusBuilder(queue);
    }
    if (queue.back() == "*"){
        return multBuilder(queue);
    }
    if (queue.back() == "/"){
        return divBuilder(queue);
    }
return new Number(0);
}

bool Evaluator::isNum(std::string &a) {
    if (a.empty()) return false;
    return isdigit(a[0]) || isalpha(a[0]);

}

Expression *Evaluator::divBuilder(std::vector<std::string> &queue) {
    queue.pop_back();
    int i = 0;

    if (isNum(queue.back())){
        std::string newnum = queue.back();
        queue.pop_back();
        if (isNum(queue.back())){
            std::string newnum2 = queue.back();
            queue.pop_back();
            return new Div(newnum2, newnum);
        } else return new Div(expressionBuilder(queue),newnum);
    }
    while (i + 1 < queue.size()){
        if(isNum(queue[i]) && isNum(queue[i+1])){
            if (i+2 < queue.size()){
                if (isNum(queue[i+2])) {
                    i++;
                    break;
                }
            }
            i+= 3;
            break;
        }
        i++;
    }
    std::vector<std::string> slim_up(queue.begin()+i,queue.end());
    std::vector<std::string> slim_down(queue.begin() ,queue.begin()+i);
    return new Div(expressionBuilder(slim_down),expressionBuilder(slim_up));
}

Expression *Evaluator::multBuilder(std::vector<std::string> &queue) {
    queue.pop_back();
    int i = 0;
    if (isNum(queue.back())){
        std::string newnum = queue.back();
        queue.pop_back();
        if (isNum(queue.back())){
            std::string newnum2 = queue.back();
            queue.pop_back();
            return new Mul(newnum2, newnum);
        } else return new Mul(expressionBuilder(queue),newnum);
    }
    while (i + 1 < queue.size()){
        if(isNum(queue[i]) && isNum(queue[i+1])){
            if (i+2 < queue.size()){
                if (isNum(queue[i+2])) {
                    i++;
                    break;
                }
            }
            i+=3;
            break;
        }
        i++;
    }
    std::vector<std::string> slim_up(queue.begin()+i,queue.end());
    std::vector<std::string> slim_down(queue.begin() ,queue.begin()+i);
    return new Mul(expressionBuilder(slim_down),expressionBuilder(slim_up));
}

Expression *Evaluator::minusBuilder(std::vector<std::string> &queue) {
    queue.pop_back();
    int i = 0;

    if (isNum(queue.back())){
        std::string newnum = queue.back();
        queue.pop_back();
        if (isNum(queue.back())){
            std::string newnum2 = queue.back();
            queue.pop_back();
            return new Minus(newnum2, newnum);
        } else return new Minus(expressionBuilder(queue),newnum);
    }
    while (i + 1 < queue.size()){
        if(isNum(queue[i]) && isNum(queue[i+1])){
            if (i+2 < queue.size()){
                if (isNum(queue[i+2])) {
                    i++;
                    break;
                }
            }
            i+= 3;
            break;
        }
        i++;
    }
    std::vector<std::string> slim_up(queue.begin()+i,queue.end());
    std::vector<std::string> slim_down(queue.begin() ,queue.begin()+i);
    return new Minus(expressionBuilder(slim_down),expressionBuilder(slim_up));
}

Expression *Evaluator::plusBuilder(std::vector<std::string> &queue) {
    queue.pop_back();
    int i = 0;

    if (isNum(queue.back())){
        std::string newnum = queue.back();
        queue.pop_back();
        if (isNum(queue.back())){
            std::string newnum2 = queue.back();
            queue.pop_back();
            return new Plus(newnum2, newnum);
        } else return new Plus(expressionBuilder(queue),newnum);
    }
    while (i + 1 < queue.size()){
        if(isNum(queue[i]) && isNum(queue[i+1])){
            if (i+2 < queue.size()){
                if (isNum(queue[i+2])) {
                    i++;
                    break;
                }
            }
            i+= 3;
            break;
        }
        i++;
    }
    std::vector<std::string> slim_up(queue.begin()+i,queue.end());
    std::vector<std::string> slim_down(queue.begin() ,queue.begin()+i);
    return new Plus(expressionBuilder(slim_down),expressionBuilder(slim_up));
}


