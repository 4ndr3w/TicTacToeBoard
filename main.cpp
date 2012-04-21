#include "TicTacToeGame.h"
#include "TicTacToeIO.h"
#include "TicTacToeAI.h"
#define MODE_TWO 1
#define MODE_AI 2

int gameMode = -1;

void twoPlayer()
{
	TicTacToeIO *IO = TicTacToeIO::GetInstance();
	int cyclesChange = 0;
	while ( true )
	{
		TicTacToeGame game;
		while( !game.isOver() )
		{
			if ( game.isXMove() )
			{
				IO->setStatus(PLAYER_X);
				int button = IO->getButton();
				if ( game.Take(button, PLAYER_X) )
					game.XMoved();
			}
			else if ( game.isOMove() )
			{
				IO->setStatus(PLAYER_O);
				int button = IO->getButton();
				if ( game.Take(button, PLAYER_O) )
					game.OMoved();
			}
			
			if ( IO->changeModePressed() )
				cyclesChange++;
			else cyclesChange = 0;
			if ( cyclesChange > 100)
			{
				gameMode = MODE_AI;
				return;
			}	
			
			IO->setStatus(OFF);
			game.Draw();
		}
		
		if ( game.isStalemate() )
		{
			IO->setLED(0, RED);
			IO->setLED(1, RED);
			IO->setLED(3, RED);
			
			IO->setLED(5, BLUE);
			IO->setLED(7, BLUE);
			IO->setLED(8, BLUE);
			
			IO->setStatus(GREEN);
		}
		else
		{
			int winner = game.getWinner();
			if ( winner == PLAYER_X )
			{
				IO->setStatus(PLAYER_X);
				
				for ( int i=0; i<9; i++ )
					IO->setLED(i, PLAYER_X);
			}
			else if ( winner == PLAYER_O )
			{
				IO->setStatus(PLAYER_O);
				
				for ( int i=0; i<9; i++ )
					IO->setLED(i, PLAYER_O);
			}
			
		}
		
		_delay_ms(1500);
		
		game.Reset();
		
	}
}

void aiGame()
{
	TicTacToeIO *IO = TicTacToeIO::GetInstance();
	
	int cyclesChange = 0;
	while(true)
	{
		if ( IO->changeModePressed() )
			cyclesChange++;
		else cyclesChange = 0;
		
		if ( cyclesChange > 100)
		{
			gameMode = MODE_TWO;
			return;
		}
		
		TicTacToeGame game;
		TicTacToeAI ai((TicTacToeGame*)&game, PLAYER_X, PLAYER_O);
		while ( !game.isOver() )
		{
			if ( game.isXMove() )
			{
				IO->setStatus(PLAYER_X);
				ai.makeMove();
				game.XMoved();
			}
			else if ( game.isOMove() )
			{
				IO->setStatus(PLAYER_O);
				int button = IO->getButton();
				if ( game.Take(button, PLAYER_O) )
					game.OMoved();
			}
			game.Draw();
		}
		
		if ( game.isStalemate() )
		{
			IO->setLED(0, RED);
			IO->setLED(1, RED);
			IO->setLED(3, RED);
			
			IO->setLED(5, BLUE);
			IO->setLED(7, BLUE);
			IO->setLED(8, BLUE);
			
			IO->setStatus(GREEN);
		}
		else
		{
			int winner = game.getWinner();
			if ( winner == PLAYER_X )
			{
				for ( int i = 0; i < 3; i++ )
				{
					IO->setStatus(PLAYER_X);
					_delay_ms(500);
					IO->setStatus(OFF);
					_delay_ms(500);
				}
			}
			else if ( winner == PLAYER_O )
			{
				for ( int i = 0; i < 3; i++ )
				{
					IO->setStatus(PLAYER_O);
					_delay_ms(500);
					IO->setStatus(OFF);
					_delay_ms(500);
				}
			}
			
		}
		
		_delay_ms(1500);
		
		game.Reset();
		
	}
}

int main()
{
	while(true)
	{
		switch ( gameMode )
		{
			case MODE_TWO:
				twoPlayer();
				break;
			
			case MODE_AI:
				aiGame();
				break;
			
			default:
				gameMode = MODE_TWO;
				break;
		}
		
		for ( int i = 0; i < 9; i++ )
			TicTacToeIO::GetInstance()->setLED(i, 0);
		
		TicTacToeIO::GetInstance()->setStatus(GREEN);
		_delay_ms(500);
		TicTacToeIO::GetInstance()->setStatus(RED);
		_delay_ms(500);
		TicTacToeIO::GetInstance()->setStatus(BLUE);
		_delay_ms(500);
		TicTacToeIO::GetInstance()->setStatus(GREEN);
		_delay_ms(500);
	}
	twoPlayer();
	while(true)	TicTacToeIO::GetInstance()->setStatus(GREEN);
}
