#pragma once
#include "Header.h"
#include <iostream>
using namespace std;

class Board;

class Piece
{
protected:

	Position m_pos{};
	COLOR m_color{};
	Board* m_B;
	bool firstMove = false;
public:
	

	Piece(Position pos, COLOR color, Board* B);
	virtual bool isLegalMove(Position);
	virtual void Draw();
	void UnDraw();
	void Move(Position Dest);
	COLOR getColor();

	virtual bool AmIKing();
	virtual bool AmIPawn();
	virtual bool AmIRook();

	bool& FirstMove();
	bool isHorizontal(Position Src, Position Dest);
	bool isVertical(Position Src, Position Dest);
	bool isDiagonal(Position Src, Position Dest);
	bool isHorizontalPathClear(Position Src, Position Dest);
	bool isVerticalPathClear(Position Src, Position Dest);
	bool isDiagonalPathClear(Position Src, Position Dest);
	
	~Piece();

};

