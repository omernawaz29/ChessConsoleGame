#include "King.h"
#include "Board.h"

King::King(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool King::isLegalMove(Position Dest)
{
	if (m_B->getPiece(Dest) != nullptr && m_B->getPiece(Dest)->AmIKing())
		return false;

	
	if (abs(m_pos.ri - Dest.ri) == 1 || abs(m_pos.ci - Dest.ci) == 1)
	{
		return ((isVertical(m_pos, Dest) && isVerticalPathClear(m_pos, Dest))
			|| (isHorizontal(m_pos, Dest) && isVerticalPathClear(m_pos, Dest))
			|| (isDiagonal(m_pos, Dest) && isDiagonalPathClear(m_pos, Dest)));
	}
	return false;

}

void King::Draw()
{
	int color;
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int sr = m_pos.ri * 10 + 1, sc = m_pos.ci * 10 + 1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoRowCol(sr+1, sc+4);
	cout << char(-37) << char(-37);

	gotoRowCol(sr + 2, sc + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(sr +3, sc + 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(sr + 4, sc + 4);
	cout << char(-37) << char(-37);

	gotoRowCol(sr + 5, sc + 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(sr + 6, sc + 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(sr + 7, sc + 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	

}

bool King::AmIKing()
{
	return true;
}

King::~King()
{
}
