//
// Created by elyawy on 12/16/18.
//

#include "sleepCommand.h"

void sleepCommand::execute() {

}

void sleepCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void sleepCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}
