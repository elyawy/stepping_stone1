//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    std::mutex mtx;
    std::string var = mapH.getparseQueue()->front();
    if (mapH.getsymblTable()->count(var) == 0) {
        mapH.getParsed()->push(mapH.getparseQueue()->front());
        mapH.getparseQueue()->pop();
        if (!mapH.getparseQueue()->empty()){
            if (mapH.getparseQueue()->front() == "=") {
                mapH.getParsed()->push(mapH.getparseQueue()->front());
                mapH.getparseQueue()->pop();
                if (!mapH.getparseQueue()->empty()){
                    if (mapH.getparseQueue()->front() == "bind") {
                        mtx.lock();
                        mapH.getsymblTable()->emplace(var,0);
                        mtx.unlock();
                        mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
                    } else {
                        double x = mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
                        mtx.lock();
                        mapH.getsymblTable()->emplace(var,x);
                        mtx.unlock();
                        mapH.getParsed()->push(mapH.getparseQueue()->front());
                        mapH.getparseQueue()->pop();
                    }
                }
            } else {
                mtx.lock();
                mapH.getsymblTable()->emplace(var, 0);
                mtx.unlock();
            }
        }
    } else throw "can't initialize same variable twice";
}

void DefineVarCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string DefineVarCommand::stringify() {
    return std::__cxx11::string();
}


DefineVarCommand::~DefineVarCommand() = default;
