//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "whileCommand.h"
#include "printCommand.h"
#include "sleepCommand.h"
#include "ConnectServerCommand.h"
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
    std::vector<std::string>::iterator iter;
    for (iter = toParse.begin(); iter != toParse.end(); iter++){
        CommandTable[*iter]->execute(iter);
    }
}

Interpreter::Interpreter(){

    CommandTable.emplace("var", new DefineVarCommand);
    CommandTable.emplace("openDataServer", new OpenServerCommand);
    CommandTable.emplace("connect", new ConnectServerCommand);
    CommandTable.emplace("while", new whileCommand);
    CommandTable.emplace("print", new printCommand);
    CommandTable.emplace("sleep", new sleepCommand);

}

std::map<std::string, Command *> Interpreter::getCommands() {
    return CommandTable;
}


