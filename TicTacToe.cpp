
#include "TicTacToe.h"

// TicTacToe

char currentPlayer;
char board[3][3];

TicTacToe::TicTacToe()
{
  currentPlayer = 'X';
  board = {};
}

string toString();
char getCurrentPlayer();
bool isDone();
char getWinner();
bool isValidMove(int row, int col);
void makeMove(int row, int col);