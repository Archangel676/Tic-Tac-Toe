
#include "TicTacToe.h"
#include <string>

using namespace std;

// TicTacToe
const int row = 3;
const int col = 3;

TicTacToe::TicTacToe()
{
  currentPlayer = 'X';

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j] = '-';
    }
  }
}

string TicTacToe::toString()
{
  string boardString = "";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j < 2)
        boardString = board[i][j] + " ";
      else
        boardString = board[i][j];
    }
    boardString += "\n";
  }

  return boardString;
}

char TicTacToe::getCurrentPlayer()
{
  if (currentPlayer = 'X')
    return 'X';
  else
    return 'O';
}

bool TicTacToe::isDone()
{
  return false;
}

char TicTacToe::getWinner()
{
  return 'L';
}

bool TicTacToe::isValidMove(int row, int col)
{
  return false;
}

void TicTacToe::makeMove(int row, int col)
{
}
