#pragma once
#include "Piece.h"

class Rook :
    public Piece
{
public:
    Rook(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    bool AmIRook();
    ~Rook();
};

