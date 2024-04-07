
#include "TicTacToe.h"
#include <string>

using namespace std;

// TicTacToe

TicTacToe::TicTacToe()
{
  int row = 3;
  int col = 3;
  currentPlayer = 'X';

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j] = '-';
    }
  }
}

string TicTacToe::toString()
{
  int row = 3;
  int col = 3;

  string boardString = "";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j < 2)
        boardString = boardString + board[i][j] + " ";
      else
        boardString = boardString + board[i][j];
    }
    if (i < 2)
      boardString += "\n";
  }

  return boardString;
}

char TicTacToe::getCurrentPlayer()
{
  if (currentPlayer == 'X')
    return 'X';
  else
    return 'O';
}

bool TicTacToe::isValidMove(int row, int col)
{
  if ((row >= 0) && (row <= 2)) {
    if ((col >= 0) && (col <= 2)) {
      if (board[row][col] == '-') {
        return true;
      }
    }
  }
  return false;
}

void TicTacToe::makeMove(int row, int col)
{
  if (isValidMove(row, col)) {
    board[row][col] = currentPlayer;
    if (currentPlayer == 'X')
      currentPlayer = 'O';
    else
      currentPlayer = 'X';
  }
}

char TicTacToe::getWinner()
{
  // three in a row,
  for (int i = 0; i < 3; i++) {
    int rowCountX = 0;
    int rowCountO = 0;
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 'X') {
        rowCountX++;
      } else if (board[i][j] == 'O') {
        rowCountO++;
      }
    }
    if (rowCountX >= 3)
      return 'X';
    else if (rowCountO >= 3)
      return 'O';
  }

  // three in a column,

  // or three on one of the two diagonals).

  // If so, return the winner ('X' or 'O').
  // If no one has won, returns '-'.
  return 'L';
}

bool TicTacToe::isDone()
{
  return false;
}