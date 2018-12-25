//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"



void Interpreter::lexer(std::string& line) {
    l.lex(line,toParse);
    tokenized = l.getTOKENS();
    mapH.setTokens(tokenized);
}

void Interpreter::parser() {
    p.addMaps(mapH);
    p.parse(toParse, tokenized);
}

Interpreter::Interpreter() {
    mapH.setSymbleMap(&symblTable);
    mapH.setbindtovarMap(&bindtoVarTable);
    mapH.setbindtovarMap(&vartoBindTable);
    mapH.settoParse(&toParse);
    mapH.setExpresssions(&ExpressTable);
    mapH.setParsed(&parsed);
    mapH.setparseQueue(&parseQueue);
}

mapHandler *Interpreter::getMapH() {
    return &mapH;
}

void Interpreter::Calculator() {
    mapH.setParsed(&parsed);
    mapH.setparseQueue(&parseQueue);

    mapH.getExpressions()->at(parseQueue.front())->calculate(mapH);


    std::map<std::string, Expression*>::iterator maper;

    mapH.gettoParse()->clear();
    mapH.getTokens()->clear();
}

Interpreter::~Interpreter() = default;



