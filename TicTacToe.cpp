
#include "TicTacToe.h"
#include <string>

using namespace std;

// TicTacToe

TicTacToe::TicTacToe()
{
  currentPlayer = 'X';
  board[3][3];

  int row = 3;
  int col = 3;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j] = '-';
    }
  }
}

string toString()
{
  return "string";
}

char getCurrentPlayer()
{
  return 'a';
}

bool isDone()
{
  return false;
}

char getWinner()
{
  return 'L';
}

bool isValidMove(int row, int col)
{
  return false;
}

void makeMove(int row, int col)
{
}