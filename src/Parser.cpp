//
// Created by elyawy on 12/18/18.
//

#include <string>
#include <vector>
#include "Parser.h"
#include "Command.h"

void Parser::parse(std::vector<std::string> &toParse,std::map<std::string , SECONDSTAGE > *tokenized) {
    std::vector<std::string>::iterator iter;
    tokens = tokenized;

    if (tokens->at(toParse[0]) == KEYWORD){
        if (toParse[0] == "print" || toParse[0] == "var" ) oneArg(toParse);
    }

//    for (int i = 0; i < toParse.size()-1; i++) {
//        if (tokenized->at(toParse[i]) == );
//    }

    for (iter = toParse.begin(); iter != toParse.end(); iter++){
        mapH.getCommandTable()->at(*iter)->execute(iter);
    }
    while(!toParse.empty()) toParse.pop_back();
}


void Parser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

Expression *Parser::shuntingYard() {

    return nullptr;
}

void Parser::twoArgs(std::vector<std::string> &toParse) {

}

void Parser::oneArg(std::vector<std::string> &toParse) {

}
