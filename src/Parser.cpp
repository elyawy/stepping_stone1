//
// Created by elyawy on 12/18/18.
//

#include <string>
#include <vector>

#include "Parser.h"
#include "Command.h"
#include "CommandExpression.h"
#include "printCommand.h"

void Parser::parse(std::vector<std::string> &toParse,std::map<std::string , SECONDSTAGE > *tokenized) {
    std::vector<std::string>::iterator iter;
    std::vector<CommandExpression*> toExecute;
    tokens = tokenized;

    if (tokens->at(toParse[0]) == KEYWORD){
        if (toParse[0] == "print" || toParse[0] == "var" ) oneArg(toParse);
    }

    while(!toParse.empty()) toParse.pop_back();
    if(!tokens->empty()) tokens->clear();
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

Expression *Parser::expressionFactory(std::vector<std::string> &toParse) {
    int i = 0;
    while (i < toParse.size()) {
        if (mapH.getTokens()->at(toParse[i]) == TOEVALUTE) {

        } else if (mapH.getTokens()->at(toParse[i]) == KEYWORD){

        } else if (mapH.getTokens()->at(toParse[i]) == VARIABLE){

        } else if (mapH.getTokens()->at(toParse[i]) == QUOTED){

        }
    }
}

