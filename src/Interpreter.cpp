//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"
#include "DefineVarCommand.h"
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
    while(!toParse.empty()){
        toParse.pop_back();
    }
}

Interpreter::Interpreter() {

    CommandTable.emplace("var", 3);
    CommandTable.emplace("openDataServer", 2);
    CommandTable.emplace("connect", 2);
    CommandTable.emplace("while", 4);
    CommandTable.emplace("print", 1);
    CommandTable.emplace("sleep", 1);

}


