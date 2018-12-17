//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"




void Interpreter::lexer(std::string& line) {

    std::istringstream iss(line);
    while(!iss.eof()) {
        std::string temp;
        iss >> temp;
        toParse.push_back(temp);
    }
}

void Interpreter::parser() {

    std::vector<std::string>::iterator iter;

    for (iter = toParse.begin(); iter != toParse.end(); iter++){
        CommandTable[*iter]->execute(iter);
    }
    while(!toParse.empty()){
        toParse.pop_back();
    }
}



std::map<std::string, Command *> Interpreter::getCommands() {
    return CommandTable;
}

Interpreter::Interpreter() {
    std::map<std::string, Command * >::iterator iter;
    for (iter = CommandTable.begin(); iter != CommandTable.end(); iter++){
        (*iter).second->addSymblMapPointer(this->symblTable);
    }
}



