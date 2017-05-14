//
// Created by Devin Morgan on 5/13/2017.
//

#ifndef CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
#define CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H

#include <stdbool.h>
#include "ChessBoard.h"

typedef struct {
    ChessPiece piece;
    BoardPosition start;
    BoardPosition end;
} PlayerMove;

typedef struct {
    ChessPiece grid[8][8];
    Color teamColor;
    bool canMove;
    bool inCheck;
    bool gameOver;
    PlayerMove currentMove;
    PlayerMove lastMove;
} GameState;

bool validBoardLocation(BoardPosition position);

bool isAnAllyPiece(BoardPosition position, GameState gameState);

bool isAnEnemyPiece(BoardPosition position, GameState gameState);

bool isPieceOfType(BoardPosition position, PieceType type, GameState gameState);

bool pieceIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState);

bool moveWouldNotPutSelfInCheck(BoardPosition start, BoardPosition end, GameState gameState);

bool checkIfCurrentPlayerIsInCheck(GameState gameState);

bool pieceCanLegallyMoveToDestination(BoardPosition start, BoardPosition end, GameState gameState);

void updateGameStateWithMove(BoardPosition* pStartPos, BoardPosition* pEndLoc, GameState* pGameState);

#endif //CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
