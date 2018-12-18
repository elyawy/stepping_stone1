//
// Created by elyawy on 12/18/18.
//

#include "bindCommand.h"


void bindCommand::execute(std::vector<std::string>::iterator &iter) {
        iter--;
        std::string a = *iter;
        iter += 2;
        if ((*iter) == "bind"){
            iter++;
            mapH.getvartobindMap()->emplace(a, *iter);
            mapH.getbindtovarMap()->emplace(*iter, a);
        } else {
            double b = stoi(*iter);
            mapH.getsymblTable()->at(a) = b;
        }
    }


void bindCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

bindCommand::~bindCommand() = default;
