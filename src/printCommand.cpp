//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"
#include <algorithm>

void printCommand::execute(std::vector<std::string>::iterator &iter) {
    if (tokenized->at(mapH.gettoParse()->at(1)) == QUOTED){
        toPrint = mapH.gettoParse()->at(1);
        std::cout << toPrint << std::endl;
    } else if(tokenized->at(mapH.gettoParse()->at(1)) == TOEVALUTE) {


    }



//    iter++;
//
//    if (mapH.getsymblTable()->count(*iter) > 0 ){
//
//        std::cout << mapH.getsymblTable()->at(*iter) << std::endl;
//    }
//
//    if ((*iter)[0] == '\"') {
//        do {
//            if ((*iter)[(*iter).size()-1] == '\"') {
//                (*iter).erase(std::remove((*iter).begin(),(*iter).end(), '\"'), (*iter).end());
//                std::cout << (*iter);
//                break;
//            }
//            (*iter).erase(std::remove((*iter).begin(),(*iter).end(), '\"'), (*iter).end());
//            std::cout << *iter << " ";
//            iter++;
//
//        } while (!(*iter).empty());
//        std::cout << std::endl;
//    }
}

void printCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void printCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}
