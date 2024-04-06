
#include "TicTacToe.h"
#include <string>

using namespace std;

// TicTacToe

TicTacToe::TicTacToe()
{
  currentPlayer = 'X';
  int row = 3;
  int col = 3;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j < 2) {
        board[i][j] = '-';
      } else
        board[i][j] = '-\n';
    }
  }
}

string TicTacToe::toString()
{
  return "string";
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
