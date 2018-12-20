//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "whileCommand.h"

void whileCommand::execute(std::vector<std::string>::iterator &iter) {
    bool condition = checkCondition(iter);
    checkCondition(iter);

}

void whileCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void whileCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}
