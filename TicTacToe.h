#include <iostream>
#include <string>
using namespace std;

class TicTacToe{
public:
	TicTacToe();
	~TicTacToe();
	bool playGame();
private:
	char board[3][3];
	char player1symbol;
	char player2symbol;
	char currentPlayer;
	int x,y;
	bool isOver;

	bool checkWin();
	bool takeTurn();
	void clearBoard();
	void drawBoard();
	
	
};
