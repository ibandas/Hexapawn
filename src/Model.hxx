#pragma once

class Model
{
public:

    Model();

    struct Point;
    class Player;

    void choose_moves(int move_number);

    Player get_winner() const;
    void print_legal_moves() const;
    bool is_game_over() const;
    Player get_currentPlayer() const;

private:
    Point[] get_legal_moves();

    bool Check_MoveForward(Point current_position);
    bool Check_MoveDiagonal(Point current_position);
};


struct Model::Point{
    int x = 0;
    int y = 0;
};

class Model::Player
{
public:
    enum class Name {A, B};
    Player();
    Point[] get_pawns() const;

    void MakeMove(int move);
};








