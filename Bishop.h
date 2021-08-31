#pragma once
#include "Piece.h"

class Bishop :
    public Piece
{
public:
    Bishop(Position pos, COLOR col, Board* B);
    bool isLegalMove(Position);
    void Draw();
    ~Bishop();
};

