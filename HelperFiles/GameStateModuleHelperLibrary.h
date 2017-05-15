//
// Created by Devin Morgan on 5/13/2017.
//

#ifndef CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
#define CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H

#include <stdbool.h>
#include "ChessBoard.h"

typedef struct {
    BoardPosition grid[8][8];
    Color teamColor;
    bool canMove;
    bool inCheck;
    bool gameOver;
} GameState;

bool isAnAllyPiece(Coordinate position, GameState gameState);

bool isAnEnemyPiece(Coordinate position, GameState gameState);

bool isPieceOfType(Coordinate position, PieceType type, GameState gameState);

bool pieceIsCapableOfMovingToLocation(Coordinate start, Coordinate end, GameState gameState);

bool moveWouldPutSelfInCheck(Coordinate start, Coordinate end, GameState gameState);

bool currentPlayerIsInCheck(GameState gameState);

bool pieceCanLegallyMoveToDestination(Coordinate start, Coordinate end, GameState gameState);

void permanentlyUpdateGameStateWithMove(Coordinate start, Coordinate end, GameState *pGameState);

#endif //CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
