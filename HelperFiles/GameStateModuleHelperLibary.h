//
// Created by Devin Morgan on 5/13/2017.
//

#ifndef CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
#define CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H

#include <stdbool.h>
#include "ChessBoard.h"
#include "../GameStateModule.h"

bool validBoardLocation(BoardPosition position);

bool isAnAllyPiece(BoardPosition position, GameState gameState);

bool isAnEnemyPiece(BoardPosition position, GameState gameState);

bool isPieceOfType(BoardPosition position, PieceType type, GameState gameState);

bool pieceIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState);

bool moveWouldNotPutKingInCheck(BoardPosition start, BoardPosition end, GameState gameState);

#endif //CHESSCONSOLE_GAMESTATEMODULEHELPERLIBARY_H
