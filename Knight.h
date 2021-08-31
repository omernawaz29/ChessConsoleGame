#pragma once
#include "Piece.h"

class Knight :
    public Piece
{
public:
    Knight(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    ~Knight();
};

