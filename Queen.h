#pragma once
#include "Piece.h"

class Queen :
    public Piece
{
public:
    Queen(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    ~Queen();
};

