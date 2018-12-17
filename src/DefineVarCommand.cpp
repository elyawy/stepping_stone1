//
// Created by elyawy on 12/16/18.
//

#include "DefineVarCommand.h"

void DefineVarCommand::execute(std::vector<std::string>::iterator &iter) {


}

void DefineVarCommand::addSymblMapPointer(std::map<std::string, double> &symblTable) {
    Command::addSymblMapPointer(symblTable);
}


DefineVarCommand::~DefineVarCommand() = default;
