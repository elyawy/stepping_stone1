//
// Created by ziv_t on 12/16/18.
//

#include <iostream>
#include "ExpTest.h"

void ExpTest::run() {
    Expression* x = new Number(5);
    Expression* y = new Number(9);
    std::vector<std::string>::iterator iter;
    Expression* test_1 = new Plus(x, new Mul(y, 2));
    if (test_1->calculate(iter) == 23) {
        std::cout << "pass\n";
    } else {
        std::cout << "fail\n";
    }
    Expression* test_2 = new Div(new Minus(x, 4), new Div(9, y));
    if (test_2->calculate(iter) == 1) {
        std::cout << "pass\n";
    } else {
        std::cout << "fail\n";
    }
}
