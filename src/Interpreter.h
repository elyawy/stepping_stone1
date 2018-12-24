//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_INTERPRETER_H
#define STEPPING_STONE1_INTERPRETER_H

#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Command.h"
#include "Expression.h"
#include <string>
#include <map>
#include <vector>



class Interpreter {
private:
std::map<std::string, double> symblTable;
std::map<std::string, std::string> vartoBindTable;
std::map<std::string, std::string> bindtoVarTable;
std::map<std::string, Expression*> ExpressTable;
std::vector<std::string> toParse;
std::vector<std::string> parsed;
mapHandler mapH;
Lexer l;
Parser p;
std::map<std::string , SECONDSTAGE > *tokenized;

public:

    Interpreter();


void lexer(std::string & line);

void parser();

void Calculator();

mapHandler *getMapH();

~Interpreter();

};


#endif //STEPPING_STONE1_INTERPRETER_H
