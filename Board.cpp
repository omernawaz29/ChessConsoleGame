#include "Board.h" 
#include "Header.h"
#include<conio.h>  
#include<iostream> 
#include<windows.h>
#include <mmsystem.h>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);

}
void changeFontSize(int fontsize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = fontsize;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}
//BUTTONS AND LETTER DRAW/WRITE FUNCTIONS!
void DrawBG(int ri, int ci, int color = YELLOW)
{
	for (int r = ri; r < ri + 10; r++)
	{
		for (int c = ci; c < ci + 10; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(-37);
		}
	}
}
void DrawBorder(int ri, int ci, int color = BROWN)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int r = ri; r < ri + 10; r++)
	{
		gotoRowCol(r, ci);
		cout << char(-37);

		gotoRowCol(r, ci + 10 - 1);
		cout << char(-37);
	}
	for (int c = ci; c < ci + 10; c++)
	{
		gotoRowCol(ri, c);
		cout << char(-37);

		gotoRowCol(ri + 10 - 1, c);
		cout << char(-37);
	}
}
void DrawU(int ri, int ci, int color = BROWN)
{

	DrawBG(ri, ci);
	DrawBorder(ri, ci);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(ri + 2 + i, ci + 2);
		cout << char(-37);
	}

	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(ri + 2 + i, ci + 7);
		cout << char(-37);
	}

	for (int i = 0; i < 4; i++)
	{
		gotoRowCol(ri + 7, ci + 3 + i);
		cout << char(-37);
	}


}
void DrawR(int ri, int ci, int color = BROWN)
{
	DrawBG(ri, ci);
	DrawBorder(ri, ci);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(ri + 2, ci + 2 + i);
		cout << char(-37);
	}

	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(ri + 5, ci + 2 + i);
		cout << char(-37);
	}

	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(ri + 2 + i, ci + 2);
		cout << char(-37);
	}

	gotoRowCol(ri + 3, ci + 7);
	cout << char(-37);

	gotoRowCol(ri + 4, ci + 7);
	cout << char(-37);

	gotoRowCol(ri + 6, ci + 4);
	cout << char(-37) << char(-37);

	gotoRowCol(ri + 7, ci + 6);
	cout << char(-37) << char(-37);




}
void DrawS(int ri, int ci, int color = BROWN)
{
	DrawBG(ri, ci);
	DrawBorder(ri, ci);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int i = 0; i < 4; i++)
	{
		gotoRowCol(ri + 2, ci + 3 + i);
		cout << char(-37);
	}

	for (int i = 0; i < 4; i++)
	{
		gotoRowCol(ri + 5, ci + 3 + i);
		cout << char(-37);
	}

	for (int i = 0; i < 5; i++)
	{
		gotoRowCol(ri + 7, ci + 2 + i);
		cout << char(-37);
	}

	gotoRowCol(ri + 3, ci + 2);
	cout << char(-37);

	gotoRowCol(ri + 4, ci + 2);
	cout << char(-37);

	gotoRowCol(ri + 3, ci + 7);
	cout << char(-37);

	gotoRowCol(ri + 6, ci + 7);
	cout << char(-37);

}
void DrawL(int ri, int ci, int color = BROWN)
{
	DrawBG(ri, ci);
	DrawBorder(ri, ci);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(ri + 2 + i, ci + 2);
		cout << char(-37);
	}

	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(ri + 7, ci + 2 + i);
		cout << char(-37);
	}
}
void WriteA(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ";
	gotoRowCol(++ri, ci);
	cout << "    /\\    ";
	gotoRowCol(++ri, ci);
	cout << "   /  \\   ";
	gotoRowCol(++ri, ci);
	cout << "  / /\\ \\  ";
	gotoRowCol(++ri, ci);
	cout << " / ____ \\ ";
	gotoRowCol(++ri, ci);
	cout << "/_/    \\_\\";

}
void WriteB(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ____  ";
	gotoRowCol(++ri, ci);
	cout << "|  _ \\ ";
	gotoRowCol(++ri, ci);
	cout << "| |_) |";
	gotoRowCol(++ri, ci);
	cout << "|  _ < ";
	gotoRowCol(++ri, ci);
	cout << "| |_) |";
	gotoRowCol(++ri, ci);
	cout << "|____/ ";
}
void WriteC(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "  _____ ";
	gotoRowCol(++ri, ci);
	cout << " / ____|";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "| |____ ";
	gotoRowCol(++ri, ci);
	cout << " \\_____|";
}
void WriteD(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _____  ";
	gotoRowCol(++ri, ci);
	cout << "|  __ \\ ";
	gotoRowCol(++ri, ci);
	cout << "| |  | |";
	gotoRowCol(++ri, ci);
	cout << "| |  | |";
	gotoRowCol(++ri, ci);
	cout << "| |__| |";
	gotoRowCol(++ri, ci);
	cout << "|_____/ ";
}
void WriteE(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ______ ";
	gotoRowCol(++ri, ci);
	cout << "|  ____|";
	gotoRowCol(++ri, ci);
	cout << "| |__   ";
	gotoRowCol(++ri, ci);
	cout << "|  __|  ";
	gotoRowCol(++ri, ci);
	cout << "| |____ ";
	gotoRowCol(++ri, ci);
	cout << "|______|";
}
void WriteF(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ______ ";
	gotoRowCol(++ri, ci);
	cout << "|  ____|";
	gotoRowCol(++ri, ci);
	cout << "| |__   ";
	gotoRowCol(++ri, ci);
	cout << "|  __|  ";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "|_|     ";
}
void WriteG(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "  _____ ";
	gotoRowCol(++ri, ci);
	cout << " / ____|";
	gotoRowCol(++ri, ci);
	cout << "| |  __ ";
	gotoRowCol(++ri, ci);
	cout << "| | |_ |";
	gotoRowCol(++ri, ci);
	cout << "| |__| |";
	gotoRowCol(++ri, ci);
	cout << " \_____|";
}
void WriteH(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _    _ ";
	gotoRowCol(++ri, ci);
	cout << "| |  | |";
	gotoRowCol(++ri, ci);
	cout << "| |__| |";
	gotoRowCol(++ri, ci);
	cout << "|  __  |";
	gotoRowCol(++ri, ci);
	cout << "| |  | |";
	gotoRowCol(++ri, ci);
	cout << "|_|  |_|";
}
void WriteK(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _  __";
	gotoRowCol(++ri, ci);
	cout << "| |/ /";
	gotoRowCol(++ri, ci);
	cout << "| ' / ";
	gotoRowCol(++ri, ci);
	cout << "|  <  ";
	gotoRowCol(++ri, ci);
	cout << "| . \\ ";
	gotoRowCol(++ri, ci);
	cout << "|_|\\_\\";
}
void WriteM(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " __  __ ";
	gotoRowCol(++ri, ci);
	cout << "|  \\/  |";
	gotoRowCol(++ri, ci);
	cout << "| \\  / |";
	gotoRowCol(++ri, ci);
	cout << "| |\\/| |";
	gotoRowCol(++ri, ci);
	cout << "| |  | |";
	gotoRowCol(++ri, ci);
	cout << "|_|  |_|";
}
void WriteT(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _______ ";
	gotoRowCol(++ri, ci);
	cout << "|__   __|";
	gotoRowCol(++ri, ci);
	cout << "   | |   ";
	gotoRowCol(++ri, ci);
	cout << "   | |   ";
	gotoRowCol(++ri, ci);
	cout << "   | |   ";
	gotoRowCol(++ri, ci);
	cout << "   |_|   ";
}
void WriteW(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "__          __";
	gotoRowCol(++ri, ci);
	cout << "\\ \\        / /";
	gotoRowCol(++ri, ci);
	cout << " \\ \\  /\\  / / ";
	gotoRowCol(++ri, ci);
	cout << "  \\ \\/  \\/ /  ";
	gotoRowCol(++ri, ci);
	cout << "   \\  /\\  /   ";
	gotoRowCol(++ri, ci);
	cout << "    \\/  \\/    ";
}
void WriteI(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _____ ";
	gotoRowCol(++ri, ci);
	cout << "|_   _|";
	gotoRowCol(++ri, ci);
	cout << "  | |  ";
	gotoRowCol(++ri, ci);
	cout << "  | |  ";
	gotoRowCol(++ri, ci);
	cout << " _| |_ ";
	gotoRowCol(++ri, ci);
	cout << "|_____|";
}
void WriteN(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _   _ ";
	gotoRowCol(++ri, ci);
	cout << "| \\ | |";
	gotoRowCol(++ri, ci);
	cout << "|  \\| |";
	gotoRowCol(++ri, ci);
	cout << "| . ` |";
	gotoRowCol(++ri, ci);
	cout << "| |\\  |";
	gotoRowCol(++ri, ci);
	cout << "|_| \\_|";
}
void WriteS(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "  _____ ";
	gotoRowCol(++ri, ci);
	cout << " / ____|";
	gotoRowCol(++ri, ci);
	cout << "| (___  ";
	gotoRowCol(++ri, ci);
	cout << " \\___ \\ ";
	gotoRowCol(++ri, ci);
	cout << " ____) |";
	gotoRowCol(++ri, ci);
	cout << "|_____/ ";
}
void WriteL(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _      ";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "| |     ";
	gotoRowCol(++ri, ci);
	cout << "| |____ ";
	gotoRowCol(++ri, ci);
	cout << "|______|";
}
void WriteR(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _____  ";
	gotoRowCol(++ri, ci);
	cout << "|  __ \\ ";
	gotoRowCol(++ri, ci);
	cout << "| |__) |";
	gotoRowCol(++ri, ci);
	cout << "|  _  / ";
	gotoRowCol(++ri, ci);
	cout << "| | \\ \\ ";
	gotoRowCol(++ri, ci);
	cout << "|_|  \\_\\";
}
void Write1(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " __ ";
	gotoRowCol(++ri, ci);
	cout << "/_ |";
	gotoRowCol(++ri, ci);
	cout << " | |";
	gotoRowCol(++ri, ci);
	cout << " | |";
	gotoRowCol(++ri, ci);
	cout << " | |";
	gotoRowCol(++ri, ci);
	cout << " |_|";
}
void Write2(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ___  ";
	gotoRowCol(++ri, ci);
	cout << "|__ \\ ";
	gotoRowCol(++ri, ci);
	cout << "   ) |";
	gotoRowCol(++ri, ci);
	cout << "  / / ";
	gotoRowCol(++ri, ci);
	cout << " / /_ ";
	gotoRowCol(++ri, ci);
	cout << "|____|";
}
void Write3(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ____  ";
	gotoRowCol(++ri, ci);
	cout << "|___ \\ ";
	gotoRowCol(++ri, ci);
	cout << "  __) |";
	gotoRowCol(++ri, ci);
	cout << " |__ < ";
	gotoRowCol(++ri, ci);
	cout << " ___) |";
	gotoRowCol(++ri, ci);
	cout << "|____/ ";
}
void Write4(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _  _   ";
	gotoRowCol(++ri, ci);
	cout << "| || |  ";
	gotoRowCol(++ri, ci);
	cout << "| || |_ ";
	gotoRowCol(++ri, ci);
	cout << "|__   _|";
	gotoRowCol(++ri, ci);
	cout << "   | |  ";
	gotoRowCol(++ri, ci);
	cout << "   |_|  ";
}
void Write5(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " _____ ";
	gotoRowCol(++ri, ci);
	cout << "| ____|";
	gotoRowCol(++ri, ci);
	cout << "| |__  ";
	gotoRowCol(++ri, ci);
	cout << "|___ \\ ";
	gotoRowCol(++ri, ci);
	cout << " ___) |";
	gotoRowCol(++ri, ci);
	cout << "|____/ ";
}
void Write6(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "   __  ";
	gotoRowCol(++ri, ci);
	cout << "  / /  ";
	gotoRowCol(++ri, ci);
	cout << " / /_  ";
	gotoRowCol(++ri, ci);
	cout << "| '_ \\ ";
	gotoRowCol(++ri, ci);
	cout << "| (_) |";
	gotoRowCol(++ri, ci);
	cout << " \\___/ ";
}
void Write7(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << " ______ ";
	gotoRowCol(++ri, ci);
	cout << "|____  |";
	gotoRowCol(++ri, ci);
	cout << "    / / ";
	gotoRowCol(++ri, ci);
	cout << "   / /  ";
	gotoRowCol(++ri, ci);
	cout << "  / /   ";
	gotoRowCol(++ri, ci);
	cout << " /_/    ";
}
void Write8(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "  ___  ";
	gotoRowCol(++ri, ci);
	cout << " / _ \\ ";
	gotoRowCol(++ri, ci);
	cout << "| (_) |";
	gotoRowCol(++ri, ci);
	cout << " > _ < ";
	gotoRowCol(++ri, ci);
	cout << "| (_) |";
	gotoRowCol(++ri, ci);
	cout << " \\___/ ";
}
void WriteArrow(int ri, int ci)
{
	gotoRowCol(ri, ci);
	cout << "     __   ";
	gotoRowCol(++ri, ci);
	cout << "     \\ \\  ";
	gotoRowCol(++ri, ci);
	cout << " _____\\ \\ ";
	gotoRowCol(++ri, ci);
	cout << "|______> >";
	gotoRowCol(++ri, ci);
	cout << "      / / ";
	gotoRowCol(++ri, ci);
	cout << "     /_/  ";
}
Board::Board() : Dim{8},BDim{10}
{
	Initialize();
}

void Board::Initialize()
{
	Ps = new Piece * *[Dim];
	for (int ri = 0; ri < Dim; ri++)
	{
		Ps[ri] = new Piece * [Dim] {};
		for (int ci = 0; ci < Dim; ci++)
		{
			if (ri == 1)
			{
				Ps[ri][ci] = new Pawn(Position{ ri,ci }, BLACK,this);
			}
			else if (ri == 6)
			{
				Ps[ri][ci] = new Pawn(Position{ ri,ci }, WHITE,this);

			}
		}
		if (ri == 0)
		{
			Ps[ri][0] = new Rook(Position{ ri,0 }, BLACK, this);
			Ps[ri][Dim - 1] = new Rook(Position{ ri,Dim - 1 }, BLACK, this);

			Ps[ri][1] = new Knight(Position{ ri,1 }, BLACK, this);
			Ps[ri][Dim - 2] = new Knight(Position{ ri,Dim - 2 }, BLACK, this);

			Ps[ri][2] = new Bishop(Position{ ri,2 }, BLACK, this);
			Ps[ri][Dim - 3] = new Bishop(Position{ ri,Dim - 3 }, BLACK, this);

			Ps[ri][3] = new Queen(Position{ ri,3 }, BLACK, this);
			Ps[ri][Dim - 4] = new King(Position{ ri,Dim - 4 }, BLACK, this);
		}

		if (ri == 7)
		{
			Ps[ri][0] = new Rook(Position{ ri,0 }, WHITE, this);
			Ps[ri][Dim - 1] = new Rook(Position{ ri,Dim - 1 }, WHITE, this);

			Ps[ri][1] = new Knight(Position{ ri,1 }, WHITE, this);
			Ps[ri][Dim - 2] = new Knight(Position{ ri,Dim - 2 }, WHITE, this);

			Ps[ri][2] = new Bishop(Position{ ri,2 }, WHITE, this);
			Ps[ri][Dim - 3] = new Bishop(Position{ ri,Dim - 3 }, WHITE, this);

			Ps[ri][3] = new Queen(Position{ ri,3 }, WHITE, this);
			Ps[ri][Dim - 4] = new King(Position{ ri,Dim - 4 }, WHITE, this);
		}
	}

}

void Board::PrintBox(int ri, int ci)
{
	int color;
	int sr = ri * BDim + 1, sc = ci * BDim + 1;

	if (ri % 2 == 0)
		color = (ci % 2 == 0 ? LIGHTGREY : DARKGREY);
	else
		color = (ci % 2 == 0 ? DARKGREY : LIGHTGREY);

	for (int r = sr; r < sr + BDim; r++)
	{
		for (int c = sc; c < sc + BDim; c++)
		{
			gotoRowCol(r, c);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			cout << char(-37);
		}
	}
}
void Board::HighLightBox(int ri, int ci, int color)
{

	int sr = ri * BDim + 1, sc = ci * BDim + 1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int r = sr; r < sr + BDim; r++)
	{
		gotoRowCol(r, sc);
		cout << char(-37);

		gotoRowCol(r, sc + BDim-1);
		cout << char(-37);
	}
	for (int c = sc; c < sc + BDim; c++)
	{
		gotoRowCol(sr, c);
		cout << char(-37);

		gotoRowCol(sr + BDim-1, c);
		cout << char(-37);
	}
}
void Board::HighlightMoves(int pr, int pc)
{
	int color = LIGHTGREEN;

	HighLightBox(pr, pc, BLUE);

	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[pr][pc]->isLegalMove(Position{ ri,ci }))
			{
				if (Ps[ri][ci] != nullptr && Ps[pr][pc]->getColor() != Ps[ri][ci]->getColor())
					color = RED;
				else 
					color = LIGHTGREEN;
				HighLightBox(ri, ci, color);
			}
		}
	}

	if (Ps[pr][pc]->AmIKing())
	{
		int castling = isCastlingPossible({ pr,pc });
		if (castling == 2)
		{
			HighLightBox( pr, pc - 2, YELLOW);
			HighLightBox(pr, pc + 2, YELLOW);
		}
		else if (castling == 1)
		{
			HighLightBox(pr, pc + 2, YELLOW);
		}
		else if (castling == -1)
		{
			HighLightBox(pr, pc - 2, YELLOW);
		}
	}

	


}
void Board::UnHighlightMoves(int pr, int pc)
{
	int color{};

	if (pr % 2 == 0)
		color = (pc % 2 == 0 ? LIGHTGREY : DARKGREY);
	else
		color = (pc % 2 == 0 ? DARKGREY : LIGHTGREY);

	if (Ps[pr][pc]->AmIKing())
	{
		int castling = isCastlingPossible({ pr,pc });
		if (castling == 2)
		{
			HighLightBox(pr, pc - 2, color);
			HighLightBox(pr, pc + 2, color);
		}
		else if (castling == 1)
		{
			HighLightBox(pr, pc + 2, color);
		}
		else if (castling == -1)
		{
			HighLightBox(pr, pc - 2, color);
		}
	}
	HighLightBox(pr, pc, color);

	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (ri % 2 == 0)
				color = (ci % 2 == 0 ? LIGHTGREY : DARKGREY);
			else
				color = (ci % 2 == 0 ? DARKGREY : LIGHTGREY);

			int sr = ri * 10 + 1, sc = ci * 10 + 1;

			if (Ps[pr][pc]->isLegalMove(Position{ ri,ci }))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

				for (int r = sr; r < sr + 10; r++)
				{
					gotoRowCol(r, sc);
					cout << char(-37);

					gotoRowCol(r, sc + 9);
					cout << char(-37);
				}
				for (int c = sc; c < sc + 10; c++)
				{
					gotoRowCol(sr, c);
					cout << char(-37);

					gotoRowCol(sr + 9, c);
					cout << char(-37);
				}
			}
		}
	}
}

void Board::DrawBoard()
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if(Ps[ri][ci] == nullptr)
				PrintBox(ri,ci);
			else
			{
				PrintBox(ri, ci);
				Ps[ri][ci]->Draw();
			}
		}
	}

	for (int ri = 0; ri <= 81; ri++)
	{
		gotoRowCol(ri, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
		cout << char(-37);

		gotoRowCol(ri, 81);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
		cout << char(-37);
	}

	for (int ci = 0; ci <= 81; ci++)
	{
		gotoRowCol(0, ci);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
		cout << char(-37);

		gotoRowCol(81, ci);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
		cout << char(-37);
	}
}

void Board::Play()
{
	Position Src{}, Dest{};
	bool isGameOver = false;
	Initialize();
	DrawBoard();
	DisplayButtons();
	SaveState(Src, Dest);
	do
	{
		isGameOver = false;

		do
		{
			if (isStaleMate(findMyKing()))
			{
				StaleMateMessage();
				gotoRowCol(50, 0);
				system("pause");
				isGameOver = true;
				break;
			}

			SelectSource(Src.ri, Src.ci);

			if (isButtonPress(Src))
				continue;
			else if (!moveValidationOfSource(Src) || !HasLegalMoves(Src))
				continue;

			HighlightMoves(Src.ri, Src.ci);

			do
			{
				SelectDestination(Dest.ri, Dest.ci);
			} while (!moveValidationOfDestination(Src, Dest) && HasLegalMoves(Src));
			if (!moveValidationOfDestination(Src, Dest))
				continue;

			SaveState(Src, Dest);
			States.back().S = Src;
			States.back().D = Dest;

			UnHighlightMoves(Src.ri, Src.ci);

			movePiece(Src, Dest);
			DisplayMove(Src, Dest);
			PlaySound(TEXT("pop.wav"), NULL, SND_SYNC);

			if (isPawnAtEnd())
			{
				PromotePawn();
			}
			if (isInCheck(findOpponentKing()))
			{
				if (isCheckMate(findOpponentKing()))
				{
					CheckMateMessage(turn);
					gotoRowCol(50, 0);
					system("pause");
					isGameOver = true;
					break;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

				gotoRowCol(3, 90);
				cout << (turn == BLACK ? "WHITE" : "BLACK") << " HAS COME IN CHECK!!!";
				Sleep(1000);
				gotoRowCol(3, 90);
				cout << "                                                         ";
			}
			else if (isInCheck(findMyKing()))
			{
				if (isCheckMate(findMyKing()))
				{
					CheckMateMessage(turn);
					gotoRowCol(50, 0);
					system("pause");
					isGameOver = true;
					break;
				}
				
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);

				gotoRowCol(3, 90);
				cout << "INVALID MOVE!! " << (turn == BLACK ? "BLACK" : "WHITE") << " MOVED INTO CHECK!!!";
				PlaySound(TEXT("dhichodi.wav"), NULL, SND_FILENAME);
				gotoRowCol(3, 90);
				cout << "                                                                      ";
				Undo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

				continue;
			}
			else if (isStaleMate(findOpponentKing()))
			{
				StaleMateMessage();
				gotoRowCol(50, 0);
				system("pause");
				isGameOver = true;
				break;
			}

			break;

		} while (true);

		turnChange();

	} while (!isGameOver);
}

void Board::turnChange()
{
	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;
}

void Board::SelectSource(int& sr, int& sc)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);
	gotoRowCol(0, 90);
	cout << "TURN: " << ((turn == BLACK) ? "BLACK" : "WHITE");

	gotoRowCol(1, 90);
	cout << "                                                               ";
	gotoRowCol(2, 90);
	cout << "                                                               ";

	gotoRowCol(1, 90);
	cout << "Select Piece!";

	getRowColbyLeftClick(sr, sc);
	sr /= 10; sc /= 10;


}
void Board::SelectDestination(int& dr, int& dc)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);
	gotoRowCol(1, 90);
	cout << "                                                               ";
	gotoRowCol(1, 90);
	cout << "Move Piece!";

	getRowColbyLeftClick(dr, dc);
	dr /= 10; dc /= 10;
}

bool Board::moveValidationOfSource(Position S)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

		if (S.ri >= 8 || S.ci >= 8)
		{
			
			gotoRowCol(3, 90);
			cout << "Invalid Move! OUT OF BOARD\n";
			Sleep(500);
			gotoRowCol(3, 90);
			cout << "                                                         ";
			return false;
		}
		else if (Ps[S.ri][S.ci] == nullptr)
		{
			gotoRowCol(3, 90);
			cout << "Invalid Move! No Piece At That Location\n";
			Sleep(500);
			gotoRowCol(3, 90);
			cout << "                                                         ";
				return false;
		}
		else if (Ps[S.ri][S.ci]->getColor() != turn)
		{
			gotoRowCol(3, 90);
			cout << "Invalid Move! Not your piece!\n";
			Sleep(500);
			gotoRowCol(3, 90);
			cout << "                                                         ";
				return false;
		}
		return true;
}
bool Board::moveValidationOfDestination(Position S, Position D)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

	if (D.ri > 8 || D.ci > 8)
	{
		gotoRowCol(3, 90);
		cout << "Invalid Move! TRYING TO MOVE OUT OF BOUNDS!";
		Sleep(500);
		gotoRowCol(3, 90);
		cout << "                                                         ";
		return false;
	}
	else if (!Ps[S.ri][S.ci]->isLegalMove(D))
	{
		if (Ps[S.ri][S.ci]->AmIKing())
		{
			int castling = isCastlingPossible({ S.ri,S.ci });

			if (castling == 2 && ((D.ri == S.ri && D.ci == S.ci + 2) || (D.ri == S.ri && D.ci == S.ci - 2)))
				return true;
			else if (castling == 1 && (D.ri == S.ri && D.ci == S.ci + 2))
				return true;
			else if (castling == -1 && (D.ri == S.ri && D.ci == S.ci - 2))
				return true;
		}

		gotoRowCol(3, 90);
		cout << "Illegal Move!";
		Sleep(500);
		gotoRowCol(3, 90);
		cout << "                                                         ";
		return false;
	}
	else
		return true;		
}

bool Board::HasLegalMoves(Position P)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[P.ri][P.ci]->isLegalMove(Position{ ri,ci }))
			{
				if (Ps[P.ri][P.ci]->AmIKing())
				{
					if (isInCheck(Position{ ri,ci }))
						continue;
				}
				return true;
			}
		}
	}
	return false;
}
void Board::movePiece(Position Src, Position Dest)
{
	if (Ps[Src.ri][Src.ci]->AmIKing())
	{
		int castling = isCastlingPossible({ Src.ri,Src.ci });

		if (castling != 0)
		{
			if (Dest.ri == Src.ri && Dest.ci == Src.ci + 2)
			{
				movePiece({ Src.ri,Src.ci + 3 }, { Dest.ri,Dest.ci - 1 });
			}
			else if (Dest.ri == Src.ri && Dest.ci == Src.ci - 2)
			{
				movePiece({ Src.ri,Src.ci - 4 }, { Dest.ri,Dest.ci + 1 });
			}
		}
	}

	Ps[Src.ri][Src.ci]->Move(Dest);
	Ps[Dest.ri][Dest.ci] = Ps[Src.ri][Src.ci];
	Ps[Src.ri][Src.ci] = nullptr;

}

Position Board::findOpponentKing()
{
	turnChange();
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->AmIKing() && Ps[ri][ci]->getColor() == turn)
			{
				turnChange();
				return Position{ ri,ci };
			}
		}
	}
	return { -1,-1 };
}
Position Board::findMyKing()
{
	turnChange();
	Position K = findOpponentKing();
	turnChange();
	return K;
}
bool Board::isInCheck(Position kingPos)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{

			if (Ps[ri][ci] != nullptr)
			{
				if (Ps[kingPos.ri][kingPos.ci] != nullptr)
				{
					if (Ps[ri][ci]->getColor() != Ps[kingPos.ri][kingPos.ci]->getColor() && Ps[ri][ci]->isLegalMove(kingPos))
						return true;
				}
				else
					if (Ps[ri][ci]->getColor() != turn && Ps[ri][ci]->isLegalMove(kingPos))
						return true;
			}
		}
	}
	return false;
}
bool Board::isStaleMate(Position kingPos)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->getColor() == turn && HasLegalMoves(Position{ ri,ci }) && !doesCauseCheck(Position{ ri,ci }, kingPos))
				return false;
		}
	}
	return true;
}
bool Board::isCheckMate(Position K)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->getColor() == Ps[K.ri][K.ci]->getColor())
			{
				if (doesBreakCheck(Position{ ri,ci }, K) || HasLegalMoves(K))
					return false;
			}
		}
	}
	return true;
}

bool Board::doesBreakCheck(Position P,Position K)
{
	if (P.ri == K.ri && P.ci == K.ci)
		return false;

	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[P.ri][P.ci]->isLegalMove(Position{ ri,ci }))
			{
				SaveState(P, Position{ ri,ci });
				Ps[ri][ci] = Ps[P.ri][P.ci];
				Ps[P.ri][P.ci] = nullptr;
				if (!isInCheck(K))
				{
					Ps = States.back().Ps;
					turn = States.back().turn;
					States.pop_back();
					return true;
				}
				Ps = States.back().Ps;
				turn = States.back().turn;
				States.pop_back();
			}
		}
	}
	return false;

}
bool Board::doesCauseCheck(Position P, Position K)
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[P.ri][P.ci]->isLegalMove(Position{ ri,ci }))
			{
				SaveState(P, Position{ ri,ci });
				Ps[ri][ci] = Ps[P.ri][P.ci];
				Ps[P.ri][P.ci] = nullptr;
				if (isInCheck(K))
				{
					Ps = States.back().Ps;
					turn = States.back().turn;
					States.pop_back();
					continue;
				}
				else
				{
					Ps = States.back().Ps;
					turn = States.back().turn;
					States.pop_back();
					return false;
				}
			}
		}
	}
	return true;
}

Piece* Board::getPiece(Position R)
{
	return Ps[R.ri][R.ci];
}
int Board::getBoxDim()
{
	return BDim;
}

void Board::SaveState(Position Src, Position Dest)
{
	State temp{};
	temp.turn = turn;
	temp.S = Src;
	temp.D = Dest;
	
	if (Ps[Src.ri][Src.ci] != nullptr && Ps[Src.ri][Src.ci]->AmIKing())
	{
		int castling = isCastlingPossible({ Src.ri,Src.ci });

		if (castling != 0)
		{
			if (Dest.ri == Src.ri && Dest.ci == Src.ci + 2)
			{
				temp.castled = 1;
			}
			else if (Dest.ri == Src.ri && Dest.ci == Src.ci - 2)
			{
				temp.castled = -1;
			}
		}
	}

	temp.Ps = new Piece * *[Dim];
	for (int ri = 0; ri < Dim; ri++)
	{
		temp.Ps[ri] = new Piece *[Dim];
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] == nullptr)
				temp.Ps[ri][ci] = nullptr;
			else
			{
				Rook* R;  Pawn* P; Knight* H; Bishop* B; Queen* Q; King* K;
				COLOR tempColor;
				R = dynamic_cast<Rook*>(Ps[ri][ci]);
				P = dynamic_cast<Pawn*>(Ps[ri][ci]);
				H = dynamic_cast<Knight*>(Ps[ri][ci]);
				B = dynamic_cast<Bishop*>(Ps[ri][ci]);
				Q = dynamic_cast<Queen*>(Ps[ri][ci]);
				K = dynamic_cast<King*>(Ps[ri][ci]);

				if (R != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new Rook(Position{ri,ci},tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
				else if (P != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new Pawn(Position{ ri,ci }, tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
				else if (H != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new Knight(Position{ ri,ci }, tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
				else if (B != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new Bishop(Position{ ri,ci }, tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
				else if (Q != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new Queen(Position{ ri,ci }, tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
				else if (K != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					temp.Ps[ri][ci] = new King(Position{ ri,ci }, tempColor, this);
					*temp.Ps[ri][ci] = *Ps[ri][ci];
				}
			}
		}
	}

	States.push_back(temp);
	return;
}

void Board::Replay()
{
	Piece*** tempPs = Ps;
	COLOR tempTurn = turn;

	Ps = States[0].Ps;
	turn = States[0].turn;
	DrawBoard();

	for (int i = 1; i < States.size(); i++)
	{
		Ps = States[i].Ps;
		turn = States[i].turn;
		int castled = States[i-1].castled;

		Position Src, Dest;
		
		Src = States[i-1].S;
		Dest = States[i-1].D;

		PrintBox(Src.ri, Src.ci);
		PrintBox(Dest.ri, Dest.ci);

		if (Ps[Src.ri][Src.ci] != nullptr)
		{
			Ps[Src.ri][Src.ci]->Draw();
		}
		else
			PrintBox(Src.ri, Src.ci);
			
		if (Ps[Dest.ri][Dest.ci] != nullptr)
		{
			Ps[Dest.ri][Dest.ci]->Draw();
		}
		else 
			PrintBox(Dest.ri, Dest.ci);

		if (castled == 1)
		{
			PrintBox(Src.ri, Src.ci + 3);
			PrintBox(Dest.ri, Dest.ci - 1);

			if (Ps[Src.ri][Dest.ci - 1] != nullptr)
			{
				Ps[Src.ri][Dest.ci - 1]->Draw();
			}
		}
		else if (castled == -1)
		{
			PrintBox(Src.ri, Src.ci - 4);
			PrintBox(Dest.ri, Dest.ci + 1);

			if (Ps[Dest.ri][Dest.ci + 1] != nullptr)
			{
				Ps[Dest.ri][Dest.ci + 1]->Draw();
			}
		}


		gotoRowCol(6, 90);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);
		system("pause");
 	}

	Ps = tempPs;
	turn = tempTurn;
	DrawBoard();

	gotoRowCol(6, 90);
	cout << "                                    ";
}
void Board::Undo()
{
	if (States.size() == 1)
		return;

	Position Src, Dest;
	Ps = States.back().Ps;
	turn = States.back().turn;
	int castled = States.back().castled;

	Src = States.back().S;
	Dest = States.back().D;

	PrintBox(Src.ri, Src.ci);
	PrintBox(Dest.ri, Dest.ci);

	if (Ps[Src.ri][Src.ci] != nullptr)
	{
		Ps[Src.ri][Src.ci]->Draw();
	}
	if (Ps[Dest.ri][Dest.ci] != nullptr)
	{
		Ps[Dest.ri][Dest.ci]->Draw();
	}

	if (castled == 1)
	{
		PrintBox(Src.ri, Src.ci+3);
		PrintBox(Dest.ri, Dest.ci-1);

		if (Ps[Src.ri][Src.ci+3] != nullptr)
		{
			Ps[Src.ri][Src.ci+3]->Draw();
		}
	}
	else if (castled == -1)
	{
		PrintBox(Src.ri, Src.ci - 4);
		PrintBox(Dest.ri, Dest.ci + 1);

		if (Ps[Src.ri][Src.ci - 4] != nullptr)
		{
			Ps[Src.ri][Src.ci - 4]->Draw();
		}
	}
	
	

	States.pop_back();
}

void Board::SaveGame()
{
	ofstream wrt("Save.txt");

	wrt << (turn == BLACK ? 0 : 1) << endl;

	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] == nullptr)
				wrt << "-- ";
			else
			{
				Rook* R;  Pawn* P; Knight* H; Bishop* B; Queen* Q; King* K;
				COLOR tempColor;
				R = dynamic_cast<Rook*>(Ps[ri][ci]);
				P = dynamic_cast<Pawn*>(Ps[ri][ci]);
				H = dynamic_cast<Knight*>(Ps[ri][ci]);
				B = dynamic_cast<Bishop*>(Ps[ri][ci]);
				Q = dynamic_cast<Queen*>(Ps[ri][ci]);
				K = dynamic_cast<King*>(Ps[ri][ci]);

				if (R != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'R' : 'r') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
				else if (P != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'P' : 'p') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
				else if (H != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'H' : 'h') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
				else if (B != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'B' : 'b') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
				else if (Q != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'Q' : 'q') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
				else if (K != nullptr)
				{
					tempColor = Ps[ri][ci]->getColor();
					wrt << (tempColor == BLACK ? 'K' : 'k') << (Ps[ri][ci]->FirstMove() ? 0 : 1) << " ";
				}
			}
		}
		wrt << endl;
	}

}
void Board::LoadGame()
{
	States.clear();
	string filename;
	gotoRowCol(0, 0);
	system("cls");
	changeFontSize(22);
	cout << "Enter File To Load(Without Extension): ";
	cin >> filename;
	changeFontSize(8);
	filename += ".txt";
	ifstream rdr(filename);
	char readchar = rdr.get();

	turn = (readchar == '0' ? BLACK : WHITE);
	COLOR tempColor{};
	bool firstMove;

	EmptyPieces(Ps);
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim;)
		{
			readchar = rdr.get();
			switch (readchar)
			{
			case '-':
				Ps[ri][ci] = nullptr;
				rdr.ignore();
				ci++;
				break;

			case 'r':
			case 'R':
				tempColor = (readchar == 'r' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new Rook(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			case 'p':
			case 'P':
				tempColor = (readchar == 'p' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new Pawn(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			case 'h':
			case 'H':
				tempColor = (readchar == 'h' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new Knight(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			case 'b':
			case 'B':
				tempColor = (readchar == 'b' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new Bishop(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			case 'q':
			case 'Q':
				tempColor = (readchar == 'q' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new Queen(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			case 'k':
			case 'K':
				tempColor = (readchar == 'k' ? WHITE : BLACK);
				firstMove = (rdr.get() == '0' ? true : false);
				Ps[ri][ci] = new King(Position{ ri,ci }, tempColor, this);
				Ps[ri][ci]->FirstMove() = firstMove;
				ci++;
				break;

			default:
				break;
			}
		}
	}
	DrawBoard();
	DisplayButtons();
}

void Board::EmptyPieces(Piece*** P)
{
	P = new Piece * *[Dim] {};
	for (int ri = 0; ri < Dim; ri++)
	{
		P[ri] = new Piece * [Dim] {};
		for (int ci = 0; ci < Dim; ci++)
		{
			P[ri][ci] = nullptr;
		}
	}
}
void Board::DisplayButtons()
{
	
	DrawU(11,90);
	gotoRowCol(11, 91);
	cout << "UNDO";
	DrawR(11,100);
	gotoRowCol(11, 101);
	cout << "REPLAY";
	DrawS(11,110);
	gotoRowCol(11, 111);
	cout << "SAVE";
	DrawL(11, 120);
	gotoRowCol(11, 121);
	cout << "LOAD";

}
bool Board::isButtonPress(Position Src)
{
	if (Src.ri == 1 && Src.ci == 9)
	{
		Undo();
		return true;
	}
	else if (Src.ri == 1 && Src.ci == 10)
	{
		Replay();
		return true;
	}
	else if (Src.ri == 1 && Src.ci == 11)
	{
		SaveGame();
		return true;
	}
	else if (Src.ri == 1 && Src.ci == 12)
	{
		LoadGame();
		SaveState(Position{ 0,0 }, Position{ 0,0 });
		return true;
	}
	else
		return false;
}

bool Board::isPawnAtEnd()
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->getColor() == turn && Ps[ri][ci]->AmIPawn())
			{
				if (turn == BLACK && ri == 7)
					return true;
				else if (turn == WHITE && ri == 0)
					return true;
			}
		}
	}
	return false;
}
Position Board::findPawnAtEnd()
{
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			if (Ps[ri][ci] != nullptr && Ps[ri][ci]->getColor() == turn && Ps[ri][ci]->AmIPawn())
			{
				if (turn == BLACK && ri == 7)
					return { ri,ci };
				else if (turn == WHITE && ri == 0)
					return { ri,ci };
			}
		}
	}
	return { -1,-1 };
}
void Board::PromotePawn()
{
	Position EP = findPawnAtEnd();

	Ps[EP.ri][EP.ci] = PawnPromotionSelect();
	Ps[EP.ri][EP.ci]->Move(EP);


	for (int bi = 90; bi <= 130; bi += 10)
	{
		DrawBG(21, bi, DBLACK);
	}
}
Piece* Board::PawnPromotionSelect()
{


	for (int bi = 90; bi <= 120; bi += 10)
	{
		DrawBG(21, bi,DARKGREY);
	}

	gotoRowCol(21, 93);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);
	cout << "PICK PIECE TO PROMOTE YOUR PAWN TO";

	Queen* Q = new Queen({ 2,9 },turn,this);
	Q->Draw();
	Rook* R = new Rook({ 2,10 }, turn, this);
	R->Draw();
	Knight* H = new Knight({ 2,11 }, turn, this);
	H->Draw();
	Bishop* B = new Bishop({ 2,12 }, turn, this);
	B->Draw();

	int ri, ci;
	do
	{
		getRowColbyLeftClick(ri, ci);
		ri /= 10;
		ci /= 10;
	} while (ri != 2 && !(ci >= 9 && ci <= 12));
	
	
	

	switch (ci)
	{
	case 9:
		return Q;
	case 10:
		return R;
	case 11:
		return H;
	case 12: 
		return B;
	default:
		return nullptr;
	}
}

int Board::isCastlingPossible(Position S)
{
	bool left = false, right=false;
	if (S.ci != 4 || Ps[S.ri][S.ci] == nullptr || !Ps[S.ri][S.ci]->AmIKing() || !Ps[S.ri][S.ci]->FirstMove())
		return 0;


	if (Ps[S.ri][S.ci]->isHorizontalPathClear(S, { S.ri,S.ci - 3 }) && Ps[S.ri][S.ci - 4] != nullptr 
		&&  Ps[S.ri][S.ci -4]->AmIRook() && Ps[S.ri][S.ci -4]->FirstMove()==true)
	{
		left = true;
		for (int i = 0; i < 4; i++)
		{
			if (isInCheck({ S.ri, S.ci - i }))
				left = false;
		}
	}
	if (Ps[S.ri][S.ci]->isHorizontalPathClear(S, { S.ri,S.ci + 2 }) && Ps[S.ri][S.ci + 3] != nullptr
		&& Ps[S.ri][S.ci + 3]->AmIRook() && Ps[S.ri][S.ci + 3]->FirstMove()==true)
	{
		right = true;
		for (int i = 0; i < 3; i++)
		{
			if (isInCheck({ S.ri, S.ci + i }))
				right = false;
		}
	}

	if (right && left)
		return 2;
	else if (right)
		return 1;
	else if (left)
		return -1;
	else
		return 0;
}
void Board::DisplayMove(Position Src, Position Dest)
{
	int ri = 32; int ci = 90;
	Src.ri++; Src.ci++; Dest.ci++; Dest.ri++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

	for (int r = ri-1; r <= ri + 6; r++)
	{
		for (int c = ci-1; c <= ci + (12 * 4); c++)
		{
			gotoRowCol(r, c);
			cout << " ";
		}
	}

	switch (Src.ri)
	{
	case 1:
		WriteA(ri, ci);
		break;
	case 2:
		WriteB(ri, ci);
		break;
	case 3:
		WriteC(ri, ci);
		break;
	case 4:
		WriteD(ri, ci);
		break;
	case 5:
		WriteE(ri, ci);
		break;
	case 6:
		WriteF(ri, ci);
		break;
	case 7:
		WriteG(ri, ci);
		break;
	case 8:
		WriteH(ri, ci);
		break;
	}

	ci += 12;

	switch (Src.ci)
	{
	case 1:
		Write1(ri, ci);
		break;
	case 2:
		Write2(ri, ci);
		break;
	case 3:
		Write3(ri, ci);
		break;
	case 4:
		Write4(ri, ci);
		break;
	case 5:
		Write5(ri, ci);
		break;
	case 6:
		Write6(ri, ci);
		break;
	case 7:
		Write7(ri, ci);
		break;
	case 8:
		Write8(ri, ci);
		break;
	}
	
	ci += 12;
	WriteArrow(ri, ci);
	ci += 12;

	switch (Dest.ri)
	{
	case 1:
		WriteA(ri, ci);
		break;
	case 2:
		WriteB(ri, ci);
		break;
	case 3:
		WriteC(ri, ci);
		break;
	case 4:
		WriteD(ri, ci);
		break;
	case 5:
		WriteE(ri, ci);
		break;
	case 6:
		WriteF(ri, ci);
		break;
	case 7:
		WriteG(ri, ci);
		break;
	case 8:
		WriteH(ri, ci);
		break;
	}
	
	ci += 12;

	switch (Dest.ci)
	{
	case 1:
		Write1(ri, ci);
		break;
	case 2:
		Write2(ri, ci);
		break;
	case 3:
		Write3(ri, ci);
		break;
	case 4:
		Write4(ri, ci);
		break;
	case 5:
		Write5(ri, ci);
		break;
	case 6:
		Write6(ri, ci);
		break;
	case 7:
		Write7(ri, ci);
		break;
	case 8:
		Write8(ri, ci);
		break;
	}
}

void Board::CheckMateMessage(COLOR turn)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

	int ri = 15; int ci = 15;
	WriteC(ri, ci);
	ci += 12;
	WriteH(ri, ci);
	ci += 12;
	WriteE(ri, ci);
	ci += 12;
	WriteC(ri, ci);
	ci += 12;
	WriteK(ri, ci);
	ci += 12;
	WriteM(ri, ci);
	ci += 12;
	WriteA(ri, ci);
	ci += 12;
	WriteT(ri, ci);
	ci += 12;
	WriteE(ri, ci);
	ci += 12;

	ri += 8;
	ci = 15;

	if (turn == BLACK)
	{
		WriteB(ri, ci);
		ci += 12;
		WriteL(ri, ci);
		ci += 12;
		WriteA(ri, ci);
		ci += 12;
		WriteC(ri, ci);
		ci += 12;
		WriteK(ri, ci);
		ci += 12;
	}
	else if (turn == WHITE)
	{
		WriteW(ri, ci);
		ci += 16;
		WriteH(ri, ci);
		ci += 12;
		WriteI(ri, ci);
		ci += 12;
		WriteT(ri, ci);
		ci += 12;
		WriteE(ri, ci);
		ci += 12;
	}

	ci += 12;
	WriteW(ri, ci);
	ci += 16;
	WriteI(ri, ci);
	ci += 10;
	WriteN(ri, ci);
	ci += 12;
	WriteS (ri, ci);
	ci += 12;



}
void Board::StaleMateMessage()
{

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);
	int ri = 15; int ci = 15;
	WriteS(ri, ci);
	ci += 12;
	WriteT(ri, ci);
	ci += 12;
	WriteA(ri, ci);
	ci += 12;
	WriteL(ri, ci);
	ci += 12;
	WriteE(ri, ci);
	ci += 12;
	WriteM(ri, ci);
	ci += 12;
	WriteA(ri, ci);
	ci += 12;
	WriteT(ri, ci);
	ci += 12;
	WriteE(ri, ci);
	ci += 12;

	ri += 8;
	ci = 15;

	WriteG(ri, ci);
	ci += 12;
	WriteA(ri, ci);
	ci += 12;
	WriteM(ri, ci);
	ci += 12;
	WriteE(ri, ci);
	ci += 24;
	WriteD(ri, ci);
	ci += 12;
	WriteR(ri, ci);
	ci += 12;
	WriteA(ri, ci);
	ci += 12;
	WriteW(ri, ci);
	ci += 16;
	WriteN(ri, ci);
	ci += 12;
}

Board::~Board()
{

}

