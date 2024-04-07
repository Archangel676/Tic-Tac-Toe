
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
  // three in a row
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
    if (rowCountX == 3)
      return 'X';
    else if (rowCountO == 3)
      return 'O';
  }

  // three in a column
  for (int i = 0; i < 3; i++) {
    int colCountX = 0;
    int colCountO = 0;
    for (int j = 0; j < 3; j++) {
      if (board[j][i] == 'X') {
        colCountX++;
      } else if (board[j][i] == 'O') {
        colCountO++;
      }
    }
    if (colCountX == 3)
      return 'X';
    else if (colCountO == 3)
      return 'O';
  }

  // or three on one of the two diagonals
  // Top left to bottom right
  for (int i = 0; i < 3; i++) {
    int diagonalCountX = 0;
    int diagonalCountO = 0;
    if (board[i][i] == 'X') {
      diagonalCountX++;
    } else if (board[i][i] == 'O') {
      diagonalCountO++;
    }
    if (diagonalCountX == 3)
      return 'X';
    else if (diagonalCountO == 3)
      return 'O';
  }

  // Bottom left to top right
  for (int i = 2; i >= 0; i--) {
    int diagonalCountX = 0;
    int diagonalCountO = 0;
    int j = 2 - i;
    while (j <= 2) {
      if (board[i][j] == 'X') {
        diagonalCountX++;
      } else if (board[i][j] == 'O') {
        diagonalCountO++;
      }
    }
    if (diagonalCountX == 3)
      return 'X';
    else if (diagonalCountO == 3)
      return 'O';
  }

  // If so, return the winner ('X' or 'O').
  return '-';
}

bool TicTacToe::isDone()
{
  return false;
}