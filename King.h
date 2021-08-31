#pragma once
#include "Piece.h"


class King :
    public Piece
{
public:
    King(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    bool AmIKing();
    ~King();
};

