//
// Created by elyawy on 12/18/18.
//

#include <string>
#include <vector>
#include "Parser.h"
#include "Command.h"

void Parser::parse(std::vector<std::string> &toParse) {
    std::vector<std::string>::iterator iter;

    for (iter = toParse.begin(); iter != toParse.end(); iter++){
        mapH.getCommandTable()->at(*iter)->execute(iter);
    }
    while(!toParse.empty()) toParse.pop_back();
}


void Parser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}
