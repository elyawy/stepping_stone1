//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"

void printCommand::execute(std::vector<std::string>::iterator &iter) {
    Interpreter l;

    iter++;

    if (symblTable->count(*iter) > 0 ){

        std::cout << symblTable->at(*iter) << std::endl;
    }

    if ((*iter)[0] == '\"') {
        do {
            if ((*iter)[(*iter).size()-1] == '\"') {
                std::cout << *iter;
                break;
            }
            std::cout << *iter;
            iter++;

        } while (!(*iter).empty());
        std::cout << std::endl;
    }

}

void printCommand::addSymblMapPointer(std::map<std::string, double> &symblTable1) {
    symblTable = &symblTable1;
}
