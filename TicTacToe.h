#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToe {
private:
  char currentPlayer;
  char board[3][3];

public:
  /**
   * @brief Constructs a new Tic Tac Toe object.
   *        Sets default starting player to X and
   *        initialized board with - characters
   */
  TicTacToe();

  /**
   * @brief
   *
   * @return std::string
   */
  std::string toString();

  /**
   * @brief Get the Current Player object
   *
   * @return char
   */
  char getCurrentPlayer();

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isDone();

  /**
   * @brief Get the Winner object
   *
   * @return char
   */
  char getWinner();

  /**
   * @brief
   *
   * @param row
   * @param col
   * @return true
   * @return false
   */
  bool isValidMove(int row, int col);

  /**
   * @brief
   *
   * @param row
   * @param col
   */
  void makeMove(int row, int col);
};

#endif