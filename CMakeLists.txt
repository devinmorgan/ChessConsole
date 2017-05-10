cmake_minimum_required(VERSION 3.7)
project(ChessConsole)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ChessBoard.c ChessBoard.h)
add_executable(ChessConsole ${SOURCE_FILES} ChessBoard.c ChessBoard.h)