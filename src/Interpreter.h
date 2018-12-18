//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_INTERPRETER_H
#define STEPPING_STONE1_INTERPRETER_H


#include "Lexer.h"
#include "Parser.h"
#include "Command.h"
#include "Expression.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "ConnectServerCommand.h"
#include "whileCommand.h"
#include "printCommand.h"
#include "sleepCommand.h"
#include "bindCommand.h"
#include <string>
#include <map>
#include <vector>

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
                                                {"sleep", new sleepCommand},
                                                {"=", new bindCommand}};

std::map<std::string, Expression*> ExpressTable;
std::vector<std::string> toParse;
mapHandler mapH;
Lexer l;
Parser p;

public:

    Interpreter();


void lexer(std::string & line);

void parser();


};


#endif //STEPPING_STONE1_INTERPRETER_H
