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
    BoardPosition grid[8][8];
    Color teamColor;
    bool canMove;
    bool inCheck;
    bool gameOver;
} GameState;

bool isAnAllyPiece(BoardPosition position, GameState gameState);

bool isAnEnemyPiece(BoardPosition position, GameState gameState);

bool isPieceOfType(BoardPosition position, PieceType type, GameState gameState);

bool pieceIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState);

bool moveWouldPutSelfInCheck(BoardPosition start, BoardPosition end, GameState gameState);

bool currentPlayerIsInCheck(GameState gameState);

bool pieceCanLegallyMoveToDestination(BoardPosition start, BoardPosition end, GameState gameState);

void permanentlyUpdateGameStateWithMove(BoardPosition start, BoardPosition end, GameState *pGameState);

#endif //CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
