//
// Created by elyawy on 12/18/18.
//

#include "conditionParser.h"

void conditionParser::execute(std::vector<std::string>::iterator &iter) {
    checkCondition(iter);


}




bool conditionParser::checkCondition(std::vector<std::string>::iterator &iter) {
    iter += 2;

    if (*iter == "<") return lessthan(iter);
    if (*iter == ">") return biggerthan(iter);
    if (*iter == "==") return equalto(iter);
    if (*iter == ">=") return (equalto(iter) || biggerthan(iter));
    if (*iter == "<=") return (equalto(iter) || lessthan(iter));

    return false;
}


void conditionParser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}



bool conditionParser::lessthan(std::vector<std::string>::iterator &iter){
    iter--;
    double x;
    double y;
    if(mapH.getsymblTable()->count(*iter) > 0){
        x = mapH.getsymblTable()->at(*iter);
    } else { x = stoi(*iter);}
    iter+=2;
    if(mapH.getsymblTable()->count(*iter) > 0){
        y = mapH.getsymblTable()->at(*iter);
    }  else { y = stoi(*iter);}
    return x < y;
}

bool conditionParser::biggerthan(std::vector<std::string>::iterator &iter){
    iter--;
    double x;
    double y;
    if(mapH.getsymblTable()->count(*iter) > 0){
        x = mapH.getsymblTable()->at(*iter);
    } else { x = stoi(*iter);}
    iter+=2;
    if(mapH.getsymblTable()->count(*iter) > 0){
        y = mapH.getsymblTable()->at(*iter);
    }  else { y = stoi(*iter);}
    return x > y;

}

bool conditionParser::equalto(std::vector<std::string>::iterator &iter){
    iter--;
    double x;
    double y;
    if(mapH.getsymblTable()->count(*iter) > 0){
        x = mapH.getsymblTable()->at(*iter);
    } else { x = stoi(*iter);}
    iter+=2;
    if(mapH.getsymblTable()->count(*iter) > 0){
        y = mapH.getsymblTable()->at(*iter);
    }  else { y = stoi(*iter);}
    return x == y;

}