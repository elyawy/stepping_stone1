cmake_minimum_required(VERSION 3.13)
project(stepping_stone1)

set(CMAKE_CXX_STANDARD 14)

add_executable(stepping_stone1 src/main.cpp src/Command.h src/Expression.h
        src/super-header.h src/Interpreter.h src/Interpreter.cpp
        src/OpenServerCommand.cpp src/OpenServerCommand.h src/Number.cpp
        src/Number.h src/BinaryExpression.cpp src/BinaryExpression.h
        src/Plus.cpp src/Plus.h src/Minus.cpp src/Minus.h src/Mul.cpp
        src/Mul.h src/Div.cpp src/Div.h src/test.h src/ExpTest.cpp
        src/ExpTest.h src/CommandExpression.cpp src/CommandExpression.h
        src/DefineVarCommand.cpp src/DefineVarCommand.h src/whileCommand.cpp
        src/whileCommand.h src/printCommand.cpp src/printCommand.h src/sleepCommand.cpp src/sleepCommand.h src/ConnectServerCommand.cpp src/ConnectServerCommand.h src/mapHandler.cpp src/mapHandler.h src/bindCommand.cpp src/bindCommand.h src/conditionParser.cpp src/conditionParser.h src/Parser.cpp src/Parser.h src/Lexer.cpp src/Lexer.h src/Evaluator.cpp src/Evaluator.h)