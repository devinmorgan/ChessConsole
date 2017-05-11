cmake_minimum_required(VERSION 3.7)
project(ChessConsole)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ChessGameComponents/ChessBoard.c ChessGameComponents/ChessBoard.h GameStateModule.c GameStateModule.h DisplayModule.c DisplayModule.h SerialCommunicationModule.c SerialCommunicationModule.h)
add_executable(ChessConsole ${SOURCE_FILES} ChessGameComponents/ChessBoard.c ChessGameComponents/ChessBoard.h GameStateModule.c GameStateModule.h DisplayModule.c DisplayModule.h SerialCommunicationModule.c SerialCommunicationModule.h)