#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<cwchar>
#include<string>

#define DBLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define DWHITE 15
#define BLINK 128

struct Position
{
	int ri;
	int ci;
};


enum COLOR {BLACK, WHITE};

void gotoRowCol(int rpos, int cpos);
void getRowColbyLeftClick(int& rpos, int& cpos);
void changeFontSize(int);
void DrawBG(int,int,int);
void DrawBorder(int, int, int);
void DrawU(int, int, int);
void DrawR(int, int, int);
void DrawS(int, int, int);
void DrawL(int, int, int);


void WriteA(int,int);
void WriteB(int, int);
void WriteC(int, int);
void WriteD(int, int);
void WriteE(int, int);
void WriteF(int, int);
void WriteG(int, int);
void WriteH(int, int);
void WriteK(int, int);
void WriteM(int, int);
void WriteT(int, int);
void WriteW(int, int);
void WriteI(int, int);
void WriteN(int, int);
void WriteS(int, int);
void WriteL(int, int);
void WriteR(int, int);
void Write1(int ri, int ci);
void Write2(int ri, int ci);
void Write3(int ri, int ci);
void Write4(int ri, int ci);
void Write5(int ri, int ci);
void Write6(int ri, int ci);
void Write7(int ri, int ci);
void Write8(int ri, int ci);

void WriteArrow(int ri, int ci);



