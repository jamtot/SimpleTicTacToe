#include "TicTacToe.h"
TicTacToe::TicTacToe(){
	cout << "Welcome to Tic Tac Toe." << endl;	
	clearBoard();
	drawBoard();
}

TicTacToe::~TicTacToe()
{}

bool TicTacToe::playGame(){
	player1symbol = 'X';
	player2symbol = 'O';
	currentPlayer = player1symbol;
	isOver = false;
	
	int counter = 0;
	while(isOver == false){
		if (takeTurn())
		{
			counter++;
			drawBoard();
			isOver = checkWin();
			currentPlayer = (currentPlayer==player1symbol)?player2symbol:player1symbol;	
		}
	
		if (counter >8){
			cout << "The game is a tie." << endl;
			isOver = true;
		}
	}

	char again;
	cout << "Play again?";
	cin >> again;
	if (again == 'N' || again == 'n')
		return false;
	else {
		clearBoard();
		drawBoard();
		return true;
	}
	
}
bool TicTacToe::checkWin(){
	for (int i = 0; i < 3; i++){
		if (
		( (currentPlayer == board[0][i]) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) )
		|| ( (currentPlayer == board[i][0]) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) ) 
		|| ( (currentPlayer == board[0][0]) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) ) 
		|| ( (currentPlayer == board[0][2]) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) ) 
		) {
			cout << "You win!"<<endl;			
			return true;
		}	
	}
	return false;
}

bool TicTacToe::takeTurn(){
	string player;	
	if (currentPlayer == 'X') {player = "Player 1";}
	else {player = "Player 2";}
	
	cout << player <<", please input an x coordinate: ";
	cin >> x;
	x--;
	cout << "Please input a y coordinate: ";
	cin >> y;
	y--;

	if (board[y][x] == ' '){
		board[y][x] = currentPlayer;	
		return true;
	}	else {
		return false;
	}
}

void TicTacToe::clearBoard(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::drawBoard(){
	cout << "  1 2 3" << endl <<  " -------" << endl;
	for (int i = 0; i < 3; i++){
		cout << i+1;
		for (int j = 0; j < 3; j++){
			cout << "|" << board[i][j];
		}
		cout << "|" << endl << " -------" << endl;
	}
}
