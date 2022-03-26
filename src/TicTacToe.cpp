#include "TicTacToe.hpp"

int const TicTacToe::_winningPattern[8][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }, { 2, 4, 6 } };

TicTacToe::TicTacToe() : _count(0), _turn(true), _winner(none)
{
    for (int i = 0; i < 9; ++i)
    {
        _board.push_back(i + '0');
    }
    drawBoard();
}

void TicTacToe::drawBoard() const
{
    std::cout << "     |     |     \n";
    std::cout << "  " << _board[0] << "  |  " << _board[1] << "  |  " << _board[2] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << _board[3] << "  |  " << _board[4] << "  |  " << _board[5] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << _board[6] << "  |  " << _board[7] << "  |  " << _board[8] << '\n';
    std::cout << "     |     |     \n\n";
}

void TicTacToe::checkWinner()
{
    for (int i = 0; i < 8; i++)
    {
        if ((_board[_winningPattern[i][0]] == _board[_winningPattern[i][1]]) && (_board[_winningPattern[i][1]] == _board[_winningPattern[i][2]]))
        {
            _winner = _board[_winningPattern[i][0]] == 'X' ? player_X : player_O;
        }
    }
}

bool TicTacToe::validInput(const int position)
{
    if (position < 0 || position > 8)
    {
        std::cout << "Invalid input, please give position from 0 to 8" << std::endl;
        return false;
    }
    if (_board[position] == 'O' || _board[position] == 'X')
    {
        std::cout << "You can't put where 'O' or 'X' already exist" << std::endl;
        return false;
    }
    if (_turn)
    {
        _board[position] = 'X';
        _turn = false;
    }
    else
    {
        _board[position] = 'O';
        _turn = true;
    }
    return true;
}

void TicTacToe::play()
{
    std::cout << "Your turn Player ";
    if (_turn)
        std::cout << "X" << std::endl;
    else
        std::cout << "O" << std::endl;
    std::string position;
    while (_winner == none && _count < 9)
    {
        std::cout << "Where do you want to put? say position from 0 to 8: " << std::endl;
        std::cin >> position;
        if (position == "q")
        {
            std::cout << "Quitting the game" << std::endl;
            break;
        }
        if (!validInput(std::stoi(position)))
        {
            continue;
        }
        drawBoard();
        checkWinner();
        _count++;
    }
    if (_winner != none)
    {
        std::string winner = _winner == player_X ? "player X" : "player O";
        std::cout << "The game is over, winner is: " << winner << std::endl;
    }
    if (_count == 9)
    {
        std::cout << "The game is draw !!" << std::endl;
    }
}

// setters
void TicTacToe::setBoard(const std::vector<char> &board)
{
    _board = board;
}

// getters
std::vector<char> TicTacToe::getBoard() const
{
    return _board;
}

TicTacToe::Winner TicTacToe::getWinner() const
{
    return _winner;
}