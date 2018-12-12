cmake_minimum_required(VERSION 3.13)
project(stepping_stone1)

set(CMAKE_CXX_STANDARD 14)

add_executable(stepping_stone1 src/main.cpp src/Command.h src/Expression.h src/super-header.h src/Lexer.h src/Lexer.cpp src/Parser.h src/Parser.cpp)