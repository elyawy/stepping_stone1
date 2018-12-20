//
// Created by elyawy on 12/16/18.
//

#include "ConnectServerCommand.h"

void ConnectServerCommand::execute(std::vector<std::string>::iterator &iter) {

}

void ConnectServerCommand::addMaps(mapHandler &mapHandler1) {
 mapH =mapHandler1;
}

void ConnectServerCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
  tokenized = tokenized1;
}
