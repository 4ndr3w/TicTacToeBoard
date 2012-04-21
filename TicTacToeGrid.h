#include "TicTacToeIO.h"


#ifndef TicTacToeGrid_h
#define TicTacToeGrid_h

#define SPACE_OPEN 0
#define SPACE_X 1
#define SPACE_O 2
class TicTacToeGrid
{
private:
	int Grid[9];	
public:
	TicTacToeGrid();
	
	void Reset();
	bool isOpen(int spaceID);
	bool Take(int spaceID, int playerID);
	bool Has(int spaceID, int playerID);
	int Value(int spaceID);
	void Draw();
};

#endif

