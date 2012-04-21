#include "TicTacToeGrid.h"

#ifndef TicTacToeGame_h
#define TicTacToeGame_h

#define PLAYER_X 1
#define PLAYER_O 2

class TicTacToeGame : public TicTacToeGrid
{
private:
	int lastPlay;
public:
	TicTacToeGame();
	
	void XMoved();
	void OMoved();
	bool isXMove();
	bool isOMove();
	int getWinner();
	bool isStalemate();
	bool isWinner(int playerID);
	bool isOver();
};

#endif
