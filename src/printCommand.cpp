//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"

void printCommand::execute(std::vector<std::string>::iterator &iter) {
    iter++;
    std::cout << *iter << std::endl;
}
