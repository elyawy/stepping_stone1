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
std::map<std::string, Expression*> ExpressTable;
std::vector<std::string> toParse;
std::queue<std::string> parseQueue;
std::queue<std::string> parsed;
std::queue<std::string> updated;
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


void reParse();

};


#endif //STEPPING_STONE1_INTERPRETER_H
