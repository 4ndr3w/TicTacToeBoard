#include "TicTacToeGame.h"
#ifndef TicTacToeAI_h
#define TicTacToeAI_h
class TicTacToeAI
{
private:
	TicTacToeGame *game;
	int m_aiPlayer;
	int m_opponent;
	
	bool theyhavespaces(int s1, int s2);
	bool TicTacToeAI::havespaces(int s1, int s2);
	bool isopen(int space);
	void take(int space);
public:
	TicTacToeAI(TicTacToeGame *_game, int aiPlayer, int opponent);
	void makeMove();
};
#endif
