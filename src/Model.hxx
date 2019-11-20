#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Model {
public:
    Model();
    enum class Piece {White, Black, Empty};
    enum class Player {W, B};
    //My Additions:
    struct Point {
        Point(int x, int y)
            :x{x},
             y{y}{}
        int x, y;
    };

    struct Move{

        Move(Point current_position_, Point final_position_)
            : current_position_{current_position_},
            final_position_{final_position_}{}
        Point current_position_;
        Point final_position_;
    };

    vector<Move> get_legal_moves() const ;
//    vector<Point> get_legal_moves();
    void print_legal_moves(ostream &os);
    bool check_move_forward( const Point &p) const ;
    bool check_move_right_diagonally(const Point &p) const ;
    bool check_move_left_diagonally(const Point &p)  const;
//    vector<vector<int>> add_move_forward(vector<vector<int>> legal_moves, int x, int y);
//    vector<vector<int>> add_move_right_diagonally(vector<vector<int>> legal_moves, int x, int y);
//    vector<vector<int>> add_move_left_diagonally(vector<vector<int>> legal_moves, int x, int y);
//    vector<Point> add_move_forward(vector<Point> legal_moves, Point point);
//    vector<Point> add_move_right_diagonally(vector<Point> legal_moves, Point point);
//    vector<Point> add_move_left_diagonally(vector<Point> legal_moves, Point point);

    void print_board(ostream &os) const;
    void move_pawn(Point current_position_,Point final_position_ );

    Player switch_turns(Model::Player p);
private:

    vector<vector<Piece>> board_;
    //My Additions:
    Player turn_;
};

