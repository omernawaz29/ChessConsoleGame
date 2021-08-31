#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "Piece.h"
#include "Header.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
using namespace std;


struct State
{
	Piece*** Ps;
	COLOR turn;
	Position S{}, D{};
	int castled{};
};

class Board
{
	const int Dim{};
	const int BDim{};
	vector<State> States{};
	vector<Position> Test{};
	Piece*** Ps;
	COLOR turn = WHITE;
public:
	
	Board();
	void Initialize();

	void PrintBox(int, int);
	void HighLightBox(int, int, int);
	void HighlightMoves(int, int);
	void UnHighlightMoves(int, int);

	void DrawBoard();
	void Play();
	void turnChange();

	void SelectSource(int&,int&);
	void SelectDestination(int&,int&);
	bool moveValidationOfSource(Position);
	bool moveValidationOfDestination(Position, Position);
	bool HasLegalMoves(Position);
	void movePiece(Position,Position);

	Position findOpponentKing();
	Position findMyKing();
	bool isInCheck(Position);
	bool isStaleMate(Position);
	bool isCheckMate(Position);
	bool doesBreakCheck(Position,Position);
	bool doesCauseCheck(Position, Position);
	Piece* getPiece(Position R);
	int getBoxDim();

	void SaveState(Position, Position);
	void Replay();
	void Undo();

	void SaveGame();
	void LoadGame();
	
	void EmptyPieces(Piece***);

	void DisplayButtons();
	bool isButtonPress(Position);


	bool isPawnAtEnd();
	Position findPawnAtEnd();
	void PromotePawn();
	Piece* PawnPromotionSelect();

	int isCastlingPossible(Position);

	void DisplayMove(Position,Position);
	void CheckMateMessage(COLOR turn);
	void StaleMateMessage();

	~Board();
};

