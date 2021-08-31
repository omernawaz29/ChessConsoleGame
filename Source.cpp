#include <iostream>
#include "Board.h"
using namespace std;

void StartMsg()
{
	system("cls");
	int ri = 30, ci = 130;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteC(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteH(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteE(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteS(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteS(ri, ci);
	ci += 12;

	ri += 8;
	ci = 100;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteS(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteT(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteA(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteR(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteT(ri, ci);
	ci += 12;

	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteG(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteA(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BROWN);
	WriteM(ri, ci);
	ci += 12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	WriteE(ri, ci);


	_getch();
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DWHITE);

}
int main()
{
	char toContinue;
	do {
		changeFontSize(8);
		StartMsg();
		Board B;
		B.Play();
		changeFontSize(24);
		gotoRowCol(0, 0);
		system("cls");
		cout << "Would You Like To Play Again?(Y)";
		cin >> toContinue;
	} while (toContinue == 'Y' || toContinue == 'y');
	
}