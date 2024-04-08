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
   *        initializes board with dash '-' characters
   */
  TicTacToe();

  /**
   * @brief Loops through the two dimensional array
   *        of the current board and turns it into a string
   *        that if printed to the console, will be formatted
   *        like a regular Tic Tac Toe game
   * @return std::string String containing current game log
   */
  std::string toString();

  /**
   * @brief Asks TicTacToe object who the Current Player is
   *        and returns that info as a char.
   * @return char Player who is about to make a move
   */
  char getCurrentPlayer();

  /**
   * @brief Checks a spot on the board to see if
   *        a player has already gone there or if
   *        the spot is free to play.
   * @param row Row on game board to check
   * @param col Column on game board to check
   * @return true Acceptable move, the spot is free
   * @return false Invalid move, the spot is taken
   */
  bool isValidMove(int row, int col);

  /**
   * @brief If the attempted move is a valid play,
   *        and the spot is free put the mark ('X or 'O')
   *        of the current player onto the board at that spot.
   *        Then switch current player to the opposite.
   * @param row Row on game board to check
   * @param col Column on game board to check
   */
  void makeMove(int row, int col);

  /**
   * @brief Loop through the board checking if there
   *        are any three in a rows in the rows, columns,
   *        and both diagonals for both players.
   * @return char If there is a three in a row, the
   *        player mark that won. If there is no winner,
   *        returns '-' as the default no winner char
   */
  char getWinner();

  /**
   * @brief Checks if the game has been completed, either
   *        by having a winner or by all possible moves
   *        being played, filling up the board in a cat's
   *        game or a tie.
   * @return true A winner was declared, or there are no
   *         more possible moves left to play
   * @return false No winner was declared, and there are
   *         valid moves left unplayed on the board
   */
  bool isDone();
};

#endif