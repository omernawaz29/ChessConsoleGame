#include "Rook.h"

Rook::Rook(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool Rook::isLegalMove(Position Dest)
{
	return ((isHorizontal(m_pos, Dest) && isHorizontalPathClear(m_pos, Dest))
		|| (isVertical(m_pos, Dest) && isVerticalPathClear(m_pos, Dest)));
}

void Rook::Draw()
{
	int color;
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int cr = m_pos.ri * 10 + 1 + 5, cc = m_pos.ci * 10 + 1 + 5;

	for (int r = cr - 1; r < cr - 1 + 3; r++)
	{
		for (int c = cc - 2; c < cc - 2 + 4; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(-37);
		}
	}

	for (int c = cc - 3; c < cc - 3 + 6; c += 2)
	{
		if (c == cc - 1)
		{
			gotoRowCol(cr - 2, c);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(-37);

			gotoRowCol(cr - 2, c + 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(-37);
			c++;
			continue;
		}
		gotoRowCol(cr - 2, c);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << char(-37);
	}

	gotoRowCol(cr + 2, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}

bool Rook::AmIRook()
{
	return true;
}

Rook::~Rook()
{
}
