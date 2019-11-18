#pragma once
#include <vector>

class Model
{
public:

    Model()
    {

    }

    struct Point;
    class Player;

    void create_board(int inputSize);
    void choose_moves(int move_number);
    Player get_winner() const;
    void print_legal_moves() const;
    bool is_game_over() const;
    Player get_currentPlayer() const;

private:
    std::vector<Point> get_legal_moves();

    bool Check_MoveForward(Point current_position);
    bool Check_MoveDiagonal(Point current_position);
};


struct Model::Point{
    int x, y;
};

class Model::Player
{
public:
    Player();
    // Player is either A or B. N stands for Null and used to represent an empty space
    enum class User {
        A, B, N
    };
    std::vector<Point> get_pawns() const;
    void MakeMove(int move);
};









