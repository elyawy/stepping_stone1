//
// Created by elyawy on 12/18/18.
//

#include <string>
#include <vector>

#include "Parser.h"
#include "Command.h"
#include "CommandExpression.h"
#include "printCommand.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "ConnectServerCommand.h"
#include "bindCommand.h"
#include "quotedExpression.h"

void Parser::parse(std::vector<std::string> &toParse,std::map<std::string , SECONDSTAGE > *tokenized) {
    std::vector<std::string>::iterator iter;
    std::vector<CommandExpression*> toExecute;
    tokens = tokenized;

    expressionFactory(toParse);

    mapH.getExpressions()->at("print")->calculate(mapH);

    std::map<std::string, Expression*>::iterator maper;
    maper = mapH.getExpressions()->begin();
    while (maper != mapH.getExpressions()->end()){
        delete (*maper).second;
        maper++;
    }

    mapH.getExpressions()->clear();
    toParse.clear();
    tokens->clear();
}


void Parser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void Parser::twoArgs(std::vector<std::string> &toParse) {

}

void Parser::oneArg(std::vector<std::string> &toParse) {
    if (toParse[0] == "print"){
        std::vector<std::string>::iterator iter;
        auto a = (new CommandExpression(new printCommand()));
        a->calculate(mapH);
        delete a;
    }
}

void Parser::expressionFactory(std::vector<std::string> &toParse) {
    int i = 0;
    while (i < toParse.size()) {
        if (mapH.getTokens()->at(toParse[i]) == TOEVALUTE) {
            Evaluator evaluator;
            mapH.getExpressions()->emplace("evaluate", evaluator.analizer(toParse[i]));
        } else if (mapH.getTokens()->at(toParse[i]) == KEYWORD){
            mapH.getExpressions()->emplace(toParse[i], keywordSorter(toParse[i]));
        } else if (mapH.getTokens()->at(toParse[i]) == VARIABLE){
            mapH.getExpressions()->emplace(toParse[i],new CommandExpression(new DefineVarCommand));
        } else if (mapH.getTokens()->at(toParse[i]) == QUOTED){
            mapH.getExpressions()->emplace("to_print",new quotedExpression(toParse[i]));
        }
        i++;
    }
}

Expression * Parser::keywordSorter(std::string &keyword) {
    if(keyword == "var") return new CommandExpression(new DefineVarCommand());
    if(keyword == "print") return new CommandExpression(new printCommand());
    if(keyword == "openDataServer") return new CommandExpression(new OpenServerCommand());
    if(keyword == "connect") return new CommandExpression(new ConnectServerCommand());
    if(keyword == "bind") return new CommandExpression(new bindCommand());
}

Parser::~Parser() = default;
