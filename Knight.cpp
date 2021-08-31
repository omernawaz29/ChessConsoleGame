#include "Knight.h"
#include "Board.h"

Knight::Knight(Position pos, COLOR col, Board* B) :Piece(pos, col, B)
{
	firstMove = true;
}

bool Knight::isLegalMove(Position Dest)
{
	Position Def = Position{ abs(m_pos.ri - Dest.ri), abs(m_pos.ci - Dest.ci) };
	return (((Def.ri == 2 && Def.ci == 1) || (Def.ri == 1 && Def.ci == 2))
		&& (m_B->getPiece(Dest) == nullptr || (m_B)->getPiece(Dest)->getColor() != m_color));
}

void Knight::Draw()
{
	int color;
	if (m_color == BLACK)
		color = DBLACK;
	else if (m_color == WHITE)
		color = DWHITE;

	int cr = m_pos.ri * 10 + 1 + 5, cc = m_pos.ci * 10 + 1 + 5;\

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoRowCol(cr - 3, cc - 1);
	cout << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr - 2, cc - 2);
	for (int i = 0; i < 6; i++)
		cout << char(-37);

	gotoRowCol(cr - 1, cc - 3);
	for (int i = 0; i < 4; i++)
		cout << char(-37);

	gotoRowCol(cr - 1, cc + 2);
	cout << char(-37) << char(-37);

	gotoRowCol(cr, cc - 2);
	cout << char(-37) << char(-37) << char(-37);

	gotoRowCol(cr + 1, cc - 1);
	cout << char(-37) << char(-37);

	gotoRowCol(cr + 2, cc - 3);
	for (int i = 0; i < 7; i++)
		cout << char(-37);


}

Knight::~Knight()
{
}
