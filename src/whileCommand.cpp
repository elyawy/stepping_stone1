//
// Created by elyawy on 12/16/18.
//

#include "whileCommand.h"
#include "Interpreter.h"

void whileCommand::execute(std::vector<std::string>::iterator &iter) {
    Interpreter l;

    // read and create the condition for the loop
    iter++;
    int x = stoi(*iter);
    iter++;
    iter++;
    int y = stoi(*iter);
    iter++; // '{' should be here
    if ((*iter) != "}") throw "invalid syntax";
    iter++;

    while ((*iter) != "}") {
//        while (/* condition*/) {
//            l.getCommands()[*iter]->execute(iter);
//        }
    }

}

void whileCommand::addSymblMapPointer(std::map<std::string, double> &symblTable) {
    Command::addSymblMapPointer(symblTable);
}
