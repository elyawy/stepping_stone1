//
// Created by elyawy on 12/16/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate(mapHandler &mapH) {
    std::vector<std::string>::iterator iter;
    command->addMaps(mapH);
    command->execute(iter);
//need to find a way to send iterator, before we can enable method.
}

CommandExpression::~CommandExpression(){
    delete command;
}

CommandExpression::CommandExpression(Command *command) : command(command) {

}
