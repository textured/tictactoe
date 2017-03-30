#include "tictactoe.h"
#include <iostream>

tictactoe::tictactoe(){}

bool tictactoe::placeObject(int x, int y, char currentPlayer)
{
	if (board[x - 1][y - 1] != '.')
		return false;
	else
	{
		board[x - 1][y - 1] = currentPlayer;
		return true;
	}
}

char tictactoe::checkVictory()
{
	// Vertical
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	// horizontal
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	// diagonal

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][0];

	return '.';
}

void tictactoe::startGame()
{
	tictactoe::clearBoard();

	bool GAME = true;
	char firstPlayer;
	char currentPlayer;
	int x, y;
	int turn = 0;

	std::cout << "Choose who starts (X/Y):" << std::endl;
	std::cin >> firstPlayer;

	if (firstPlayer == 'X')
		currentPlayer = 'X';
	else
		currentPlayer = 'Y';

	while (GAME)
	{
		tictactoe::printBoard();

		if (turn == 9)
		{
			std::cout << "Tie! No one won.\n Thanks for playing.";
			GAME = false;
		}

		std::cout << "Player " << currentPlayer << "'s turn:" << std::endl;
		std::cin >> x;
		std::cin >> y;

		if (!placeObject(x, y, currentPlayer))
		{
			std::cout << "Spot taken, please choose another move:\n";
		}
		else
		{
			if (tictactoe::checkVictory() == '.')
			{
				/* Change turn and increment count*/
				if (currentPlayer == 'X')
					currentPlayer = 'Y';
				else
					currentPlayer = 'X';

				turn++;
				std::cout << "TURN = " << turn << std::endl;
			}
			else
			{
				tictactoe::printBoard();
				std::cout << "Game over!\n" << currentPlayer << " won." << std::endl;
				GAME = false;
			}
		}
	}
}

void tictactoe::clearBoard()
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '.';
		}
}

void tictactoe::printBoard()
{
	std::cout << "   1 2 3 " << std::endl;
	std::cout << "  -------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout <<  i+1 << " |" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|" << std::endl;
	}
	std::cout << "  -------" << std::endl;
}
