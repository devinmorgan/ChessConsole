//
// Created by Devin Morgan on 5/9/2017.
//

#ifndef CHESSCONSOLE_CHESSGAME_H
#define CHESSCONSOLE_CHESSGAME_H

typedef enum{
    PAWN_B, KNIGHT_B, BISHOP_B, ROOK_B, QUEEN_B, KING_B,
    EMPTY,
    PAWN_W, KNIGHT_W, BISHOP_W, ROOK_W, QUEEN_W, KING_W
} ChessPiece;

void resetChessBoard(ChessPiece* pChessBoard[8][8]);



#endif //CHESSCONSOLE_CHESSGAME_H
