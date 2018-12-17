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
std::map<std::string, std::string> vartoBindTable;
std::map<std::string, std::string> bindtoVarTable;
std::map<std::string, Command*> CommandTable = {{"var", new DefineVarCommand},
                                                {"openDataServer", new OpenServerCommand},
                                                {"connect", new ConnectServerCommand},
                                                {"while", new whileCommand},
                                                {"print", new printCommand},
                                                {"sleep", new sleepCommand}};
std::map<std::string, Expression*> ExpressTable;
std::vector<std::string> toParse;
int parseState = 0;

public:

    Interpreter();


void lexer(std::string & line);

void parser();

    std::map<std::string, Command*> getCommands();

};


#endif //STEPPING_STONE1_INTERPRETER_H
