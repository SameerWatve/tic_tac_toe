#include "gtest/gtest.h"
#include "TicTacToe.hpp"

class TicTacToeTest : public ::testing::Test
{
  public:
    void SetUp() override {}

    void TearDown() override {}

  protected:
    TicTacToe testGame;
};

TEST_F(TicTacToeTest, checkHorizontalWin)
{
    std::vector<char> board(9);
    board = { '0', '1', '2', '3', '4', '5', 'X', 'X', 'X' };
    testGame.setBoard(board);
    testGame.checkWinner();
    ASSERT_EQ(testGame.getWinner(), TicTacToe::player_X);
}

TEST_F(TicTacToeTest, checkDiagonalWin)
{
    std::vector<char> board(9);
    board = { 'O', '1', '2', '3', 'O', '4', '6', '7', 'O' };
    testGame.setBoard(board);
    testGame.checkWinner();
    EXPECT_EQ(testGame.getWinner(), TicTacToe::player_O);
}

TEST_F(TicTacToeTest, validInput)
{
    int position = 10;
    EXPECT_EQ(false, testGame.validInput(position));
}