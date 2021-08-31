#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    bool AmIPawn();

    ~Pawn();
};

