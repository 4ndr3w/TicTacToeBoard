#include "TicTacToeGrid.h"
#include "TicTacToeIO.h"

TicTacToeGrid::TicTacToeGrid()
{
	Reset();
}

void TicTacToeGrid::Reset()
{
	for ( int i = 0; i < 9; i++ )
		Grid[i] = SPACE_OPEN;
}

bool TicTacToeGrid::isOpen(int spaceID)
{
	if ( spaceID >= 0 && spaceID < 9 )
		return Grid[spaceID] == SPACE_OPEN;
	return false;
}

bool TicTacToeGrid::Take(int spaceID, int playerID)
{
	if ( !isOpen(spaceID) )
		return false;
	if ( playerID > 2 || playerID < 0 )
		return false;
	Grid[spaceID] = playerID;
	return true;
}

bool TicTacToeGrid::Has(int spaceID, int playerID)
{
	if ( isOpen(spaceID) )
		return false;
	return Grid[spaceID] == playerID;
}

int TicTacToeGrid::Value(int spaceID)
{
	return Grid[spaceID];
}

void TicTacToeGrid::Draw()
{
	for ( int i = 0; i<9; i++ )
	{
		TicTacToeIO::GetInstance()->setLED(i, Grid[i]);
		_delay_ms(1);
		for ( int z = 0; z < 9; z++ )
			TicTacToeIO::GetInstance()->setLED(i, SPACE_OPEN);
	}
}
