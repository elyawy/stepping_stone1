//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_INTERPRETER_H
#define STEPPING_STONE1_INTERPRETER_H


#include <string>
#include <map>
#include <vector>
#include "Command.h"
#include "Expression.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "whileCommand.h"
#include "printCommand.h"
#include "sleepCommand.h"
#include "ConnectServerCommand.h"
#include <sstream>



class Interpreter {
private:

std::map<std::string, double> symblTable;
std::map<std::string, Expression*> ExpressTable;
std::vector<std::string> toParse;

public:

    Interpreter();


void lexer(std::string & line);

void parser();

    std::map<std::string, Command*> getCommands();

};


#endif //STEPPING_STONE1_INTERPRETER_H
