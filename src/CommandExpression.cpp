//
// Created by elyawy on 12/16/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate(mapHandler &mapH) {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
    command->addMaps(mapH);
    command->execute();
}

CommandExpression::~CommandExpression(){
    delete command;
}

CommandExpression::CommandExpression(Command *command) : command(command) {

}

std::string CommandExpression::stringify() {
    return command->stringify();
}
