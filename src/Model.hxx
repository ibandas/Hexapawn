#pragma once
#include <vector>

class Model
{
public:
    Model();
    Model(int rows, int columns);

    struct Point;
    class Player;

    // B -> Occupied by the Black Pawn.
    // W -> Occupied by the White Pawn.
    // N -> No Pawn at the current place.
    enum class OccupiedPlace{
        B, W, N
    };

    void populate_board(int rows, int columns);
    void choose_moves(int move_number);
    Player get_winner() const;
    void print_legal_moves() const;
    bool is_game_over() const;
    Player get_currentPlayer() const;
    std::vector<Point> get_legal_moves(const Player& player) const;
    void set_legal_moves(Player& player);

private:
    std::vector< std::vector<OccupiedPlace> > board_;
    Player A_;
    Player B_;
    bool check_move_forward(Point current_position) const;
    bool check_move_left_diagonal(Point current_position) const;
    bool check_move_right_diagonal(Point current_position) const;

};

struct Model::Point{
    int x, y;
    Point(int x, int y)
    :x{x}, y{y}{};
};

class Model::Player
{
public:
    Player();
    // Player is either A or B.
    enum Type { B, W };
    std::vector<Point> get_pawns() const;
    void set_pawns(Model::Point position);
    void addMoves(Point moveAvailable);
    std::vector<Point> getMoves() const;
    void MakeMove(int move);

private:
    std::vector<Point> pawns_;
    std::vector<Point> moves_available_;
};











