#include "Bishop.h"

Bishop::Bishop(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool Bishop::isLegalMove(Position Dest)
{
	return (isDiagonal(m_pos, Dest) && isDiagonalPathClear(m_pos,Dest));
}

void Bishop::Draw()
{
	int color;
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int cr = m_pos.ri*10+1 + 5, cc = m_pos.ci * 10 + 1 + 5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); 
	gotoRowCol(cr - 3, cc - 1);
	cout << char(-37) << char(-37);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	gotoRowCol(cr - 2, cc - 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr - 1, cc - 1);
	cout << char(-37) << char(-37);

	gotoRowCol(cr, cc - 1);
	cout << char(-37) << char(-37);

	gotoRowCol(cr + 1, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr + 2, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}

Bishop::~Bishop()
{
}
