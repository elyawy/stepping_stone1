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
#include "whileCommand.h"
#include "redefineVarCommand.h"
#include "ifCommand.h"

void Parser::parse(std::vector<std::string> &toParse,std::map<std::string , SECONDSTAGE > *tokenized) {
    tokens = tokenized;
    while(toParse.empty()){
        mapH.getparseQueue()->push(toParse.front());
        toParse.erase(toParse.begin());
    }

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
        if (mapH.getTokens()->at(toParse[i]) == TOEVALUTE) {
            if (mapH.getExpressions()->count(toParse[i])>0) mapH.getExpressions()->erase(toParse[i]);
            Evaluator evaluator;
            Expression * exp = evaluator.analizer(toParse[i]);
            toDelete.push(exp);
            mapH.getExpressions()->emplace(toParse[i], exp);
        } else if (mapH.getTokens()->at(toParse[i]) == KEYWORD && mapH.getExpressions()->count(toParse[i])==0){
            if (toParse[i] == "while" || toParse[i] == "if"){
                if (mapH.getTokens()->at(toParse[i+1]) != TOEVALUTE) throw "invalid syntax";
            }
            Expression * exp = keywordSorter(toParse[i]);
            mapH.getExpressions()->emplace(toParse[i], exp);
            toDelete.push(exp);
        } else if (mapH.getTokens()->at(toParse[i]) == VARIABLE){
            if (mapH.getExpressions()->count(toParse[i])>0) mapH.getExpressions()->erase(toParse[i]);
            Expression * exp = new CommandExpression(new redefineVarCommand());
            mapH.getExpressions()->emplace(toParse[i],exp);
            toDelete.push(exp);
        } else if (mapH.getTokens()->at(toParse[i]) == QUOTED){
            if (mapH.getExpressions()->count(toParse[i])>0) mapH.getExpressions()->erase(toParse[i]);
            Expression * exp = new quotedExpression(toParse[i]);
            mapH.getExpressions()->emplace(toParse[i],exp);
            toDelete.push(exp);
        }
        i++;
    }
    while(!toParse.empty()){
      mapH.getparseQueue()->push(toParse.front());
      toParse.erase(toParse.begin());
    }
}

Expression * Parser::keywordSorter(std::string &keyword) {
    if(keyword == "var") return new CommandExpression(new DefineVarCommand());
    if(keyword == "print") return new CommandExpression(new printCommand());
    if(keyword == "openDataServer") return new CommandExpression(new OpenServerCommand());
    if(keyword == "connect") return new CommandExpression(new ConnectServerCommand());
    if(keyword == "bind") return new CommandExpression(new bindCommand());
    if(keyword == "while") {return new CommandExpression(new whileCommand());}
    if(keyword == "if") return new CommandExpression(new ifCommand());
}


Parser::~Parser(){

while (!toDelete.empty()){
 delete toDelete.front();
    toDelete.pop();
}
}
