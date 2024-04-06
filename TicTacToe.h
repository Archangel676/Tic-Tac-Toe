#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToe {
private:
  char currentPlayer;
  char board[3][3];

public:
  TicTacToe();
  std::string toString();
  char getCurrentPlayer();
  bool isDone();
  char getWinner();
  bool isValidMove(int row, int col);
  void makeMove(int row, int col);
};

#endif