//
// Created by elyawy on 12/16/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate(mapHandler &mapH) {
    mapH.getExecuted()->push(mapH.getToExecute()->front());
    mapH.getToExecute()->pop();
    command->addMaps(mapH);
    command->execute();
//need to find a way to send iterator, before we can enable method.
}

CommandExpression::~CommandExpression(){
    delete command;
}

CommandExpression::CommandExpression(Command *command) : command(command) {

}

std::string CommandExpression::stringify() {
    return command->stringify();
}
