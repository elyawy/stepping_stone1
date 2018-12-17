//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"

std::map<std::string, Command*> CommandTable = {{"var", new DefineVarCommand},
                                                {"openDataServer", new OpenServerCommand},
                                                {"connect", new ConnectServerCommand},
                                                {"while", new whileCommand},
                                                {"print", new printCommand},
                                                {"sleep", new sleepCommand}};


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



