//
// Created by elyawy on 12/16/18.
//

#include "CommandExpression.h"

double CommandExpression::calculate() {
//    command->execute();
}

CommandExpression::~CommandExpression() = default;

CommandExpression::CommandExpression(Command *command) : command(command) {

}
