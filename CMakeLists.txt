cmake_minimum_required(VERSION 3.7)
project(ChessConsole)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c HelperFiles/ChessBoard.c HelperFiles/ChessBoard.h GameStateModule.c GameStateModule.h DisplayModule.c DisplayModule.h SerialCommunicationModule.c SerialCommunicationModule.h GameStateModuleHelperLibary.c GameStateModuleHelperLibary.h)
add_executable(ChessConsole ${SOURCE_FILES} HelperFiles/ChessBoard.c HelperFiles/ChessBoard.h GameStateModule.c GameStateModule.h DisplayModule.c DisplayModule.h SerialCommunicationModule.c SerialCommunicationModule.h GameStateModuleHelperLibary.c GameStateModuleHelperLibary.h)