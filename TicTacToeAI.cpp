#include "TicTacToeAI.h"

TicTacToeAI::TicTacToeAI(TicTacToeGame *_game, int aiPlayer, int opponent)
{
	game = _game;
	m_aiPlayer = aiPlayer;
	m_opponent = opponent;
}

bool TicTacToeAI::isopen(int space)
{
	return game->Value(space) == 0;
}

bool TicTacToeAI::theyhavespaces(int s1, int s2)
{
	return game->Has(s1, m_opponent) && game->Has(s2, m_opponent);
}

bool TicTacToeAI::havespaces(int s1, int s2)
{
	return game->Has(s1, m_aiPlayer) && game->Has(s2, m_aiPlayer);
}

void TicTacToeAI::take(int space)
{
	game->Take(space, m_aiPlayer);
}

void TicTacToeAI::makeMove()
{
	if ( isopen(4) )
	{
		take(4);
	}
	else if ( theyhavespaces(0,1) && isopen(2)  )
	{
		take(2);
	}
	else if ( theyhavespaces(1,2) && isopen(0)  )
	{
		take(0);
	}
	else if ( theyhavespaces(2,0) && isopen(1)  )
	{
		take(1);
	}

	// Middle Across
	else if ( theyhavespaces(3,4) && isopen(5)  )
	{
		take(5);
	}
	else if ( theyhavespaces(5,4) && isopen(3)  )
	{
		take(3);
	}
	else if ( theyhavespaces(5,3) && isopen(4)  )
	{
		take(4);
	}

	// Bottom Across
	else if ( theyhavespaces(6,7) && isopen(8)  )
	{	
		take(8);
	}
	else if ( theyhavespaces(6,8) && isopen(7)  )
	{
		take(7);
	}
	else if ( theyhavespaces(7,8) && isopen(6)  )
	{
		take(6);
	}

	// Row 1
	else if ( theyhavespaces(0,3) && isopen(6)  )
	{
		take(6);
	}
	else if ( theyhavespaces(0,6) && isopen(3)  )
	{
		take(3);
	}
	else if ( theyhavespaces(6,3) && isopen(0)  )
	{
		take(0);
	}

// Row 2
	else if ( theyhavespaces(1,4) && isopen(7)  )
	{
		take(7);
	}
	else if ( theyhavespaces(1,7) && isopen(4)  )
	{
		take(4);
	}
	else if ( theyhavespaces(7,4) && isopen(1)  )
	{
		take(1);
	}

// Row 3
	else if ( theyhavespaces(2,5) && isopen(8)  )
	{
		take(8);
	}
	else if ( theyhavespaces(5,8) && isopen(2)  )
	{
		take(2);
	}
	else if ( theyhavespaces(2,8) && isopen(5)  )
	{
		take(5);
	}

// 0,8 Diaginal
	else if ( theyhavespaces(0,4) && isopen(8)  )
	{
		take(8);
	}
	else if ( theyhavespaces(4,8) && isopen(0)  )
	{
		take(0);
	}

// 2,6 Diaginal
	else if ( theyhavespaces(2,4) && isopen(6)  )
	{
		take(6);
	}
	else if ( theyhavespaces(6,4) && isopen(2)  )
	{
		take(2);
	}

// Try2Win 
// Top Across
	else if ( havespaces(0,1) && isopen(2) )
	{
		take(2);
	}
	else if ( havespaces(1,2) && isopen(0) )
	{
		take(0);
	}
	else if ( havespaces(2,0) && isopen(1) )
	{
		take(1);
	}

// Middle Across
	else if ( havespaces(3,4) && isopen(5) )
	{
		take(5);
	}
	else if ( havespaces(5,4) && isopen(3) )
	{
		take(3);
	}
	else if ( havespaces(5,3) && isopen(4) )
	{
		take(4);
	}

// Bottom Across
	else if ( havespaces(6,7) && isopen(8) )
	{
		take(8);
	}
	else if ( havespaces(6,8) && isopen(7) )
	{
		take(7);
	}
	else if ( havespaces(7,8) && isopen(6) )
	{
		take(6);
	}

// Row 1
	else if ( havespaces(0,3) && isopen(6) )
	{
		take(6);
	}
	else if ( havespaces(0,6) && isopen(3) )
	{
		take(3);
	}
	else if ( havespaces(6,3) && isopen(0) )
	{
		take(0);
	}

// Row 2
	else if ( havespaces(1,4) && isopen(7) )
	{
		take(7);
	}
	else if ( havespaces(1,7) && isopen(4) )
	{
		take(4);
	}
	else if ( havespaces(7,4) && isopen(1) )
	{
		take(1);
	}

// Row 3
	else if ( havespaces(2,5) && isopen(8) )
	{
		take(8);
	}
	else if ( havespaces(5,8) && isopen(2) )
	{
		take(2);
	}
	else if ( havespaces(2,8) && isopen(5) )
	{
		take(5);
	}

// 0,8 Diaginal
	else if ( havespaces(0,4) && isopen(8) )
	{
		take(8);
	}
	else if ( havespaces(4,8) && isopen(0) )
	{
		take(0);
	}

// 2,6 Diaginal
	else if ( havespaces(2,4) && isopen(6) )
	{
		take(6);
	}
	else if ( havespaces(6,4) && isopen(2) )
	{
		take(2);
	}
	else
	{
		// if all else fails, pick the next available slot
		for ( int i = 0; i < 9; i++ )
		{
			if ( isopen(i) )
			{
				take(i);
				return;
			}
		}
	}
}
