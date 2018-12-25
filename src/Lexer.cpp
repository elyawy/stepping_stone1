//
// Created by elyawy on 12/18/18.
//

#include <sstream>
#include <vector>
#include "Lexer.h"

void Lexer::lex(std::string &line, std::vector<std::string> &toParse1) {
    scanned_list.clear();
    tokenizer(line);
    toParse = &toParse1;
    std::string temp = "";
    int x = (int) token_list.size();

    for (int i = 0; i < (int)token_list.size() ; i++) {


        if (token_list.at(i) == LETTER) {
           Words(line,i);
            if (i == (int)token_list.size()) break;
        }
        if (token_list.at(i) == EQUAL) {
            equals(line,i);
            if (i == (int)token_list.size()) break;
        }
        if (token_list.at(i) == quote){
            if (i == (int)token_list.size()-1) break;
            quotes(line, i);
            if (i == (int)token_list.size()) break;
        }
        if (token_list.at(i) == Bracketstart){
            Parethesis(line, i);
            if (i == (int)token_list.size()) break;
        }
        if (token_list.at(i) == CurlBracketstart || token_list.at(i) == CurlBracketend){
            Brackets(line, i);
            if (i == (int)token_list.size()) break;
        }
        if (token_list.at(i) == EQUAL){
            equals(line, i);
            if (i == (int)token_list.size()) break;
        }
    }
    token_list.clear();
}

void Lexer::tokenizer(std::string &line) {

    for (int i = 0; i < line.size(); i++) {
        tokenize(line[i],i);
    }

}

void Lexer::tokenize(char &a,int location) {
    switch (a){
        case '(':token_list.emplace(location, Bracketstart);
            return;
        case ')':token_list.emplace(location, Bracketend);
            return;
        case '{':token_list.emplace(location, CurlBracketstart);
            return;
        case '}':token_list.emplace(location, CurlBracketend);
            return;
        case '-':token_list.emplace(location, SUBSTRACT);
            return;
        case '+':token_list.emplace(location, ADD);
            return;
        case '*':token_list.emplace(location, MULTIPLY);
            return;
        case '/':token_list.emplace(location, DIVIDE);
            return;
        case '=': token_list.emplace(location, EQUAL);
            return;
        case '\"':token_list.emplace(location, quote);
            return;
        case '<': token_list.emplace(location, Conditional);
            return;
        case '>': token_list.emplace(location, Conditional);
            return;
        case ' ': token_list.emplace(location, SPACE);
            return;
        default:
            break;
    }
    if (isalpha(a) != 0) {token_list.emplace(location, LETTER);
        return;}
    if (isdigit(a) != 0){token_list.emplace(location, number);
        return;}
    token_list.emplace(location, OTHER);
}


void Lexer::quotes(std::string &line, int &i) {
    std::string temp = "";
    temp += line[i];
    i++;
    while(token_list.at(i) != quote) {
        temp += line[i];
        i++;
        if (i >= line.size()) throw "lexing gone wrong";
    }
    temp += '\"';
    toParse->push_back(temp);
    scanned_list.emplace(temp, QUOTED);
    temp = "";
}

void Lexer::Brackets(std::string &line, int &i) {
    std::string temp = "";
    if (token_list.at(i) == CurlBracketstart) {
        temp += line[i];
        toParse->push_back(temp);
        scanned_list.emplace(temp, FUNCSTART);
        temp = "";
    }
    if (token_list.at(i) == CurlBracketend){
        temp  += line[i];
        toParse->push_back(temp);
        scanned_list.emplace(temp, FUNCEND);
        temp = "";
    }

}

void Lexer::Parethesis(std::string &line, int &i) {
    std::string temp = "";
    temp += line[i];
    i++;
    int k = 1;
    while(k > 0) {
        if (token_list.at(i) == Bracketstart) k++;
        if (token_list.at(i) == Bracketend) k--;
        if (k == 0) break;
        temp += line[i];
        i++;
        if (i >= line.size()) throw "lexing gone wrong";
    }
    temp += ')';
    toParse->push_back(temp);
    scanned_list.emplace(temp, TOEVALUTE);
    temp = "";
}

void Lexer::Words(std::string &line, int &i) {
    std::string temp = "";
    while(token_list.at(i) != SPACE) {
        if(token_list.at(i) == EQUAL){
            break;
        }
        temp  += line[i];
        i++;
        if (i >= line.size()) break;
    }
    if (isCommand(temp)) {
        scanned_list.emplace(temp, KEYWORD);
        toParse->push_back(temp);
        if (temp == "openDataServer" || temp == "connect"){
            i++;
            Express(line, i);
            Express(line,i);
        }
        if (temp == "while" || temp == "if"){
            i++;
            Conditions(line, i);
        }
        if (temp == "print"){
            i++;
            Printer(line, i);
        }
        temp = "";
    } else {
        scanned_list.emplace(temp, VARIABLE);
        toParse->push_back(temp);
        temp = "";
    }
}


void Lexer::Express(std::string &line, int &i) {
    std::string temp = ""; int k = 0;
    while (token_list.at(i) == SPACE){
        i++;
    }
    while(token_list.at(i) != SPACE) {
        if (token_list.at(i) == Bracketstart)  k++;
         while ( k > 0){
             if (token_list.at(i) == Bracketend)  k--;
             temp  += line[i];
             i++;
             if (i >= line.size()) break;
         }
        temp  += line[i];
        i++;
        if (i >= line.size()) break;
    }
    scanned_list.emplace(temp, TOEVALUTE);
    toParse->push_back(temp);
}

void Lexer::equals(std::string &line, int &i) {
    scanned_list.emplace("=", EQUALS);
    toParse->push_back("=");
    std::string temp = "";
    i++;
    while(token_list.at(i) == SPACE) {
        i++;
    }
    int j = i;
    if (token_list.at(i) == LETTER){
        while (i < line.size() && line[i] != ' '){
            temp += line[i];
            i++;
            }
            if (temp == "bind") {
                scanned_list.emplace(temp, KEYWORD);
                toParse->push_back(temp);
            } else {
                while (i < line.size()){
                    temp += line[i];
                    i++;
                }
                scanned_list.emplace(temp, TOEVALUTE);
                toParse->push_back(temp);
            }
        } else {
        while (i < line.size()) {
            temp += line[i];
            i++;
        }
        scanned_list.emplace(temp, TOEVALUTE);
        toParse->push_back(temp);
    }
}

void Lexer::Conditions(std::string &line, int &i) {
    std::string temp = "";
    while(token_list.at(i) == SPACE) {
        i++;
    }
    while(token_list.at(i) != CurlBracketstart) {
        temp += line[i];
        i++;
    }
    while (temp[temp.size()-1] == ' '){
        temp.erase(temp.end()-1);
    }
    scanned_list.emplace(temp, TOEVALUTE);
    toParse->push_back(temp);
}

void Lexer::Printer(std::string &line, int &i) {
    std::string temp = "";
    while(token_list.at(i) == SPACE) {
        i++;
    }
    if (token_list.at(i) == quote) {
        quotes(line, i);
        if (i == line.size()) i--;
    } else {
        while (i < line.size()){
          temp += line[i];
          i++;
        }
        if (i == line.size()) i--;
        scanned_list.emplace(temp, TOEVALUTE);
        toParse->push_back(temp);
    }
}

std::map<std::string, SECONDSTAGE> *Lexer::getTOKENS() {
    return &scanned_list;
}

bool Lexer::isCommand(std::string &temp){
    return temp == "print" || temp == "openDataServer" || temp == "var" ||
    temp == "connect" || temp == "while" || temp == "sleep" || temp == "if";

}