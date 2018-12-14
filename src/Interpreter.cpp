//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"
#include <sstream>


void Interpreter::lexer(std::string& line) {

    std::istringstream iss(line);
    while(!iss.eof()) {
        std::string temp;
        iss >> temp;
        toParse.push_back(temp);
    }
}

void Interpreter::parser() {
    while (!toParse.empty()) {
        if ()
    }
}
