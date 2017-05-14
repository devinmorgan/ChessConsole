//
// Created by Devin Morgan on 5/13/2017.
//

#include <stdbool.h>
#include "ChessBoard.h"
#include "../GameStateModule.h"
#include "GameStateModuleHelperLibary.h""


bool validBoardLocation(BoardPosition position) {
    return 0 < position.rowIndex && position.rowIndex < 8
           && 0 < position.colIndex && position.colIndex < 8;
}

bool isAnAllyPiece(BoardPosition position, GameState gameState) {
    ChessPiece piece = gameState.grid[position.rowIndex][position.colIndex];
    return piece.color == gameState.teamColor;
}

bool isAnEnemyPiece(BoardPosition position, GameState gameState) {
    return !isAnAllyPiece(position, gameState);
}

bool isPieceOfType(BoardPosition position, PieceType type, GameState gameState) {
    ChessPiece piece = gameState.grid[position.rowIndex][position.colIndex];
    return piece.type == type;
}



bool possibleMoveForPiece(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
//    ChessPiece
}

bool noObstructionsInPath(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}

bool moveWouldNotPutKingInCheck(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}