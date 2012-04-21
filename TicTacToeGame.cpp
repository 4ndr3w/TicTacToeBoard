#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame()
{
	lastPlay = PLAYER_O;
}


bool TicTacToeGame::isXMove()
{
	return lastPlay != PLAYER_X;
}

bool TicTacToeGame::isOMove()
{
	return lastPlay != PLAYER_O;
}

int TicTacToeGame::getWinner()
{
	if ( isWinner(PLAYER_X) )
		return PLAYER_X;
	else if ( isWinner(PLAYER_O) )
		return PLAYER_O;
	return 0;
}

bool TicTacToeGame::isStalemate()
{
	for ( int i = 0; i < 9; i++ )
	{
		if ( Value(i) == SPACE_OPEN )
		return false;
	}
	return getWinner() == 0;
}

bool TicTacToeGame::isWinner(int playerID)
{
	// Left -> Right
	if ( Has(0, playerID) && Has(1, playerID) && Has(2, playerID) ) return true;
	if ( Has(3, playerID) && Has(4, playerID) && Has(5, playerID) ) return true;
	if ( Has(6, playerID) && Has(7, playerID) && Has(8, playerID) ) return true;

	// Diag
	if ( Has(0, playerID) && Has(4, playerID) && Has(8, playerID) ) return true;
	if ( Has(2, playerID) && Has(4, playerID) && Has(6, playerID) ) return true;

	// Top -> Down
	if ( Has(0, playerID) && Has(3, playerID) && Has(6, playerID) ) return true;
	if ( Has(1, playerID) && Has(4, playerID) && Has(7, playerID) ) return true;
	if ( Has(2, playerID) && Has(5, playerID) && Has(8, playerID) ) return true;

	return false;
}

bool TicTacToeGame::isOver()
{
	return getWinner() != 0|| isStalemate();
}

void TicTacToeGame::XMoved()
{
	lastPlay = PLAYER_X;
}

void TicTacToeGame::OMoved()
{
	lastPlay = PLAYER_O;
}
