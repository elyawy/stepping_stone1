cmake_minimum_required(VERSION 3.13)
project(stepping_stone1)

set(CMAKE_CXX_STANDARD 14)

add_executable(stepping_stone1 src/main.cpp src/Command.h src/Expression.h src/super-header.h src/Interpreter.h src/Interpreter.cpp src/OpenServerCommand.cpp src/OpenServerCommand.h src/Number.cpp src/Number.h src/BinaryExpression.cpp src/BinaryExpression.h src/Plus.cpp src/Plus.h)