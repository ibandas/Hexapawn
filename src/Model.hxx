#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Model {
public:


    Model();

    Model(int rows, int columns);

    enum class Piece {White, Black, Empty};

    enum class Player {W, B};

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

    //checks if game is over?
    bool is_game_over() const;

    //prints out all of the legal moves a user can perform with their pawns
    void print_legal_moves(ostream &os) const ;

    //prints the state of the model
    void print_board(ostream &os) const;

    int get_board_row_size() const;

    int get_board_column_size() const;

    Piece get_piece_at(Point p) const;

    //gets the user input for the move from the user
//    void get_user_move(istream &is, ostream &os);
    void get_user_move(int moveNumber);

    //switches the player playing the game
    void switch_turns(Model::Player p);

    //gets the player who is currently playing
    Player current_player() const ;

private:

    vector<vector<Piece>> board_;
    Player turn_;

    //gets all of the legal moves a player can perform
    vector<Move> get_legal_moves() const;

    //move a particular pawn from one position on the board to the other
    void move_pawn(Point current_position_,Point final_position_ );

    // checks if any pawn of the user has reached the end of the board
    bool is_reached_end() const;

    //Checks if a particular piece can move forward
    bool check_move_forward( const Point &p) const ;

    //Checks if a particular piece can move diagonally right
    bool check_move_right_diagonally(const Point &p) const ;

    //Checks if a particular piece can move diagonally left
    bool check_move_left_diagonally(const Point &p)  const;

};