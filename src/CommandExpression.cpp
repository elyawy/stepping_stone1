//
// Created by elyawy on 12/16/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate() {
//    command->execute();
//need to find a way to send iterator, before we can enable method.
}

CommandExpression::~CommandExpression() = default;

CommandExpression::CommandExpression(Command *command) : command(command) {

}
