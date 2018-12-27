//
// Created by elyawy on 12/16/18.
//

#include "sleepCommand.h"
#include <unistd.h>
#include <chrono>
#include <thread>


void sleepCommand::execute() {
    int x = (int)mapH.getExpressions()->at(mapH.getparseQueue()->front())->calculate(mapH);
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
    jump();
}

void sleepCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string sleepCommand::stringify() {
    return std::__cxx11::string();
}


