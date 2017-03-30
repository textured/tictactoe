#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe
{
public:
	tictactoe();
	void startGame();
private:
	char checkVictory();
	void checkMove(char currentPlayer);
	bool placeObject(int x, int y, char currentPlayer);
	void clearBoard();
	void printBoard();
	char board[3][3];
};

#endif