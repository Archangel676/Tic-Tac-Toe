//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//----------------------------------------------------------
// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//----------------------------------------------------------

#include "TicTacToe.h"
#include <string>

using namespace std;

// Tests:

TEST_CASE("constructor and toString")
{
  TicTacToe t1;
  string boardString = t1.toString();
  CHECK(boardString == "- - -\n- - -\n- - -");

  // Print just so we can see it
  cout << "---------------------------" << endl;
  cout << "Initial board:" << endl;
  cout << boardString << endl;
  cout << "---------------------------" << endl;
}

TEST_CASE("getCurrentPlayer - initial")
{
  TicTacToe t1;
  CHECK(t1.getCurrentPlayer() == 'X'); // x starts
}

TEST_CASE("makeMove1")
{
  TicTacToe t1;

  t1.makeMove(0, 0);
  string boardString = t1.toString();
  CHECK(boardString == "X - -\n- - -\n- - -");
}

TEST_CASE("makeMove2")
{
  TicTacToe t1;

  t1.makeMove(1, 2);
  string boardString = t1.toString();
  CHECK(boardString == "- - -\n- - X\n- - -");
}

TEST_CASE("make three moves")
{
  TicTacToe t1;

  t1.makeMove(1, 2);
  string boardString = t1.toString();
  CHECK(boardString == "- - -\n- - X\n- - -");

  CHECK(t1.getCurrentPlayer() == 'O'); // now O's turn

  t1.makeMove(0, 0);
  string boardString2 = t1.toString();
  CHECK(boardString2 == "O - -\n- - X\n- - -");

  t1.makeMove(0, 1);
  string boardString3 = t1.toString();
  CHECK(boardString3 == "O X -\n- - X\n- - -");

  // Print just so we can see it
  cout << "---------------------------" << endl;
  cout << "After three moves:" << endl;
  cout << boardString3 << endl;
  cout << "---------------------------" << endl;
}

TEST_CASE("isValidMove - boundaries")
{
  TicTacToe t1;

  CHECK(t1.isValidMove(-1, 2) == false);
  CHECK(t1.isValidMove(3, 0) == false);
  CHECK(t1.isValidMove(10, 2) == false);
  CHECK(t1.isValidMove(2, 10) == false);
}

TEST_CASE("isValidMove - taken squares")
{
  TicTacToe t1;

  CHECK(t1.isValidMove(1, 1) == true);
  CHECK(t1.isValidMove(2, 2) == true);

  t1.makeMove(2, 2);

  CHECK(t1.isValidMove(1, 1) == true);
  CHECK(t1.isValidMove(2, 2) == false);

  t1.makeMove(1, 1);

  CHECK(t1.isValidMove(1, 1) == false);
  CHECK(t1.isValidMove(2, 2) == false);
}

TEST_CASE("makeMove - invalid")
{
  TicTacToe t1;

  t1.makeMove(3, 0); // invalid
  string boardString = t1.toString();
  CHECK(boardString == "- - -\n- - -\n- - -");

  t1.makeMove(-2, 2); // invalid
  string boardString2 = t1.toString();
  CHECK(boardString2 == "- - -\n- - -\n- - -");

  t1.makeMove(12, 1); // invalid
  string boardString3 = t1.toString();
  CHECK(boardString3 == "- - -\n- - -\n- - -");

  t1.makeMove(0, 0);
  string boardString4 = t1.toString();
  CHECK(boardString4 == "X - -\n- - -\n- - -");

  t1.makeMove(0, 0); // taken - nothing happens
  string boardString5 = t1.toString();
  CHECK(boardString5 == "X - -\n- - -\n- - -");
}

// TEST_CASE( "getWinner - rows & cols" ) {
//     {   //scope to make t1 temporary
//         TicTacToe t1;
//         CHECK( t1.getWinner() == '-' );
//         t1.makeMove(1, 0);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 1);
//         CHECK( t1.getWinner() == '-' );
//         t1.makeMove(1, 2);
//         CHECK( t1.getWinner() == 'X' );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(1, 0);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 1);
//         t1.makeMove(2, 0);
//         CHECK( t1.getWinner() == '-' );
//         t1.makeMove(0, 2);
//         CHECK( t1.getWinner() == 'O' );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(0, 2);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 2);
//         t1.makeMove(0, 1);
//         CHECK( t1.getWinner() == '-' );
//         t1.makeMove(2, 2);
//         CHECK( t1.getWinner() == 'X' );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(0, 2);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 2);
//         t1.makeMove(1, 0);
//         t1.makeMove(1, 1);
//         CHECK( t1.getWinner() == '-' );
//         t1.makeMove(2, 0);
//         CHECK( t1.getWinner() == 'O' );
//     }
// }

// TEST_CASE( "getWinner - diagonal" ) {
//     {   //scope to make t1 temporary
//         TicTacToe t1;
//         t1.makeMove(0, 0);
//         t1.makeMove(0, 1);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 2);
//         t1.makeMove(2, 2);
//         CHECK( t1.getWinner() == 'X' );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 1);
//         t1.makeMove(0, 2);
//         t1.makeMove(2, 1);
//         t1.makeMove(2, 0);
//         CHECK( t1.getWinner() == 'O' );
//     }
// }

// TEST_CASE( "isDone - winner" ) {
//     {   //scope to make t1 temporary
//         TicTacToe t1;
//         CHECK( t1.isDone() == false );
//         t1.makeMove(1, 0);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 1);
//         CHECK( t1.isDone() == false );
//         t1.makeMove(1, 2);
//         CHECK( t1.isDone() == true );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 1);
//         t1.makeMove(0, 1);
//         t1.makeMove(0, 2);
//         t1.makeMove(2, 1);
//         CHECK( t1.isDone() == false );
//         t1.makeMove(2, 0);
//         CHECK( t1.isDone() == true );
//     }

//     {
//         TicTacToe t1;
//         t1.makeMove(0, 2);
//         t1.makeMove(0, 0);
//         t1.makeMove(1, 2);
//         t1.makeMove(0, 1);
//         t1.makeMove(2, 2);
//         CHECK( t1.isDone() == true );
//     }
// }

// TEST_CASE( "isDone - draw" ) {
//     TicTacToe t1;
//     t1.makeMove(0, 0);
//     t1.makeMove(1, 0);
//     t1.makeMove(0, 1);
//     t1.makeMove(1, 1);
//     t1.makeMove(1, 2);
//     t1.makeMove(0, 2);
//     t1.makeMove(2, 0);
//     t1.makeMove(2, 1);
//     CHECK( t1.isDone() == false );
//     t1.makeMove(2, 2);
//     CHECK( t1.isDone() == true );
//     CHECK( t1.getWinner() == '-' );
// }
