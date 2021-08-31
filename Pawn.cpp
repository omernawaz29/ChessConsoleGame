#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool Pawn::isLegalMove(Position Dest)
{
	int one = 1, two = 1;
	if (firstMove)
		two++;

	if (m_color == BLACK)
	{
		one = -one;
		two = -two;
	}

	// CHECKING DIAGONAL FOR ENEMY PIECE SO IT CAN BE KILLED!!
	if ((m_pos.ri - Dest.ri) == one && abs(m_pos.ci - Dest.ci) == 1)
	{
		if (m_B->getPiece(Dest) != nullptr && m_B->getPiece(Dest)->getColor() != m_color)
		{
			return true;
		}
	}

	//CHECKING THE VALIDATION OF VERTICAL MOVEMENT
	if (m_pos.ci == Dest.ci && ((m_pos.ri - Dest.ri) == one || (m_pos.ri - Dest.ri) == two) &&
	(m_B->getPiece(Dest) == nullptr) && isVerticalPathClear(m_pos, Dest))
	{
		return true;
	}
	return false;
}

void Pawn::Draw()
{
	int color;
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int cr = m_pos.ri * 10 + 1 + 5, cc = m_pos.ci * 10 + 1 + 5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoRowCol(cr - 2, cc - 1);
	cout << char(-37) << char(-37);

	gotoRowCol(cr - 1, cc - 2);
	cout << char(-37) << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr, cc - 1);
	cout << char(-37) << char(-37);

	gotoRowCol(cr + 1, cc - 3);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}

bool Pawn::AmIPawn()
{
	return true;
}

Pawn::~Pawn()
{
}
