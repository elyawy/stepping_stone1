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
}

mapHandler *Interpreter::getMapH() {
    return &mapH;
}

void Interpreter::Calculator() {
    mapH.getExpressions()->at("command")->calculate(mapH);

    std::map<std::string, Expression*>::iterator maper;

    maper = mapH.getExpressions()->begin();
    while (maper != mapH.getExpressions()->end()){

        delete (*maper).second;
        maper++;
    }

    mapH.getExpressions()->clear();
    mapH.gettoParse()->clear();
    mapH.getTokens()->clear();
}

Interpreter::~Interpreter() = default;



