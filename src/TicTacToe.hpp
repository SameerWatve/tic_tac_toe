#ifndef TicTacToe_H
#define TicTacToe_H

#include <iostream>
#include <vector>
#include <string>

class TicTacToe
{
  public:
    // Enum to determine who is winner of the game
    enum Winner
    {
        player_X,
        player_O,
        none
    };
    // Constructor
    TicTacToe();

    // play the game
    void play();

    // draw current state of board
    void drawBoard() const;
    // check and update winner of the game
    void checkWinner();
    // check if use has entered correct input
    bool validInput(const int position);
    // setters
    void setBoard(const std::vector<char> &board);
    // getters
    std::vector<char> getBoard() const;
    TicTacToe::Winner getWinner() const;

  private:
    // board to play game
    std::vector<char> _board;
    // game started or not
    uint16_t _count;
    // which player's turn it is, if true, player X, else player O
    bool _turn;
    // winner of the game
    Winner _winner;
    static const int _winningPattern[8][3];
};

#endif