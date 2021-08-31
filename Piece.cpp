#include "Piece.h"
#include "Board.h"

Piece::Piece(Position pos, COLOR col, Board* B)
{
	m_pos = pos;
	m_color = col;
	m_B = B;
}

bool Piece::isLegalMove(Position)
{
	return true;
}

void Piece::Draw()
{
	return;
}
void Piece::UnDraw()
{
	m_B->PrintBox(m_pos.ri, m_pos.ci);
}
void Piece::Move(Position Dest)
{
	firstMove = false;
	UnDraw();
	m_pos = Dest;
	m_B->PrintBox(m_pos.ri, m_pos.ci);
	Draw();
}

COLOR Piece::getColor()
{
	return m_color;
}

bool Piece::AmIKing()
{
	return false;
}

bool Piece::AmIPawn()
{
	return false;
}

bool Piece::AmIRook()
{
	return false;
}

bool& Piece::FirstMove()
{
	return firstMove;
}

bool Piece::isHorizontal(Position Src, Position Dest)
{
	return (Src.ri == Dest.ri);
}
bool Piece::isVertical(Position Src, Position Dest)
{
	return (Src.ci == Dest.ci);
}
bool Piece::isDiagonal(Position Src, Position Dest)
{
	return (abs(Src.ri - Dest.ri) == abs(Src.ci - Dest.ci));
}

bool Piece::isHorizontalPathClear(Position Src, Position Dest)
{
	Position Ref1 = Src, Ref2 = Dest;
	if (Src.ci > Dest.ci)
	{
		Ref1 = Dest;
		Ref2 = Src;
	}

	for (int ci = Ref1.ci + 1; ci < Ref2.ci; ci++)
	{
		if (m_B->getPiece(Position{ Ref1.ri, ci }) != nullptr)
		{
			return false;
		}

	}

	if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
		return false;
	return true;
}
bool Piece::isVerticalPathClear(Position Src, Position Dest)
{
	Position Ref1 = Src, Ref2 = Dest;
	if (Src.ri > Dest.ri)
	{
		Ref1 = Dest;
		Ref2 = Src;
	}

	for (int ri = Ref1.ri + 1; ri < Ref2.ri; ri++)
	{
		if (m_B->getPiece(Position{ ri, Ref1.ci }) != nullptr)
		{
			return false;
		}

	}

	if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
		return false;

	return true;
}
bool Piece::isDiagonalPathClear(Position Src, Position Dest)
{

	if (Src.ri == Dest.ri && Src.ci == Dest.ci)
		return false;

	if (Src.ri > Dest.ri && Src.ci < Dest.ci)
	{
		for (int ri = Src.ri-1, ci = Src.ci+1; ri > Dest.ri && ci < Dest.ci; ri--, ci++)
		{
			if (m_B->getPiece(Position{ ri,ci }) != nullptr)
			{
				return false;
			}
		}
		if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
			return false;
		return true;
	}
	else if (Src.ri > Dest.ri && Src.ci > Dest.ci)
	{
		for (int ri = Src.ri-1, ci = Src.ci-1; ri > Dest.ri && ci > Dest.ci; ri--, ci--)
		{
			if (m_B->getPiece(Position{ ri,ci }) != nullptr)
			{
				return false;
			}
		}
		if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
			return false;
		return true;
	}
	else if (Src.ri < Dest.ri && Src.ci > Dest.ci)
	{
		for (int ri = Src.ri+1, ci = Src.ci-1; ri < Dest.ri && ci > Dest.ci; ri++, ci--)
		{
			if (m_B->getPiece(Position{ ri,ci }) != nullptr)
			{
				return false;
			}
		}
		if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
			return false;
		return true;
	}
	else if (Src.ri < Dest.ri && Src.ci < Dest.ci)
	{
		for (int ri = Src.ri+1, ci = Src.ci+1; ri < Dest.ri && ci < Dest.ci; ri++, ci++)
		{
			if (m_B->getPiece(Position{ ri,ci }) != nullptr)
			{
				return false;
			}
		}
		if (m_B->getPiece(Dest) != nullptr && (m_B)->getPiece(Dest)->getColor() == m_color)
			return false;
		return true;
	}
	
	
}

Piece::~Piece()
{
}
