#include "Queen.h"

Queen::Queen(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool Queen::isLegalMove(Position Dest)
{
	return ((isHorizontal(m_pos, Dest) && isHorizontalPathClear(m_pos, Dest))
		|| (isVertical(m_pos, Dest) && isVerticalPathClear(m_pos, Dest))
		|| (isDiagonal(m_pos, Dest) && isDiagonalPathClear(m_pos, Dest)));
}

void Queen::Draw()
{
	int color{};
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int cr = m_pos.ri * 10 + 1 + 5, cc = m_pos.ci * 10 + 1 + 5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoRowCol(cr - 3, cc - 4);
	cout << char(-37) << char(-37);
	gotoRowCol(cr - 3, cc - 1);
	cout << char(-37) << char(-37);
	gotoRowCol(cr - 3, cc + 2);
	cout << char(-37) << char(-37);

	gotoRowCol(cr - 2, cc - 4);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr - 1, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr, cc - 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr + 1, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr + 2, cc - 4);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}

Queen::~Queen()
{
}
