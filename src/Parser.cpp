//
// Created by elyawy on 12/18/18.
//

#include <string>
#include <vector>

#include "Parser.h"
#include "Command.h"
#include "printCommand.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "ConnectServerCommand.h"
#include "bindCommand.h"
#include "quotedExpression.h"
#include "varExpression.h"

void Parser::parse(std::vector<std::string> &toParse,std::map<std::string , SECONDSTAGE > *tokenized) {
    tokens = tokenized;
    expressionFactory(toParse);
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
        std::string id = std::to_string(i);
        if (mapH.getTokens()->at(toParse[i]) == TOEVALUTE) {
            Evaluator evaluator;
            Expression * exp = evaluator.analizer(toParse[i]);
            mapH.getExpressions()->emplace(id, exp);
        } else if (mapH.getTokens()->at(toParse[i]) == KEYWORD){
            Expression * exp = keywordSorter(toParse[i]);
            toExecute.push_back(exp);
            mapH.getExpressions()->emplace(id, exp);
        } else if (mapH.getTokens()->at(toParse[i]) == VARIABLE){
            if (i==0) {mapH.getExpressions()->emplace(id,new varExpression(toParse[i]));
            } else mapH.getExpressions()->emplace(id,new varExpression(toParse[i]));
        } else if (mapH.getTokens()->at(toParse[i]) == QUOTED){
            mapH.getExpressions()->emplace(id,new quotedExpression(toParse[i]));
        }
        i++;
    }
    i = 0;
    while(i < mapH.getExpressions()->size()){
      mapH.getToExecute()->emplace(std::to_string(i));
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
