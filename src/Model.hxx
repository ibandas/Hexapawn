#pragma once
#include <vector>

using namespace std;

class Model {
public:
    Model();
    enum class Piece {White, Black, Empty};
    enum class Player {W, B};


    vector<vector<int>> get_legal_moves();
    void print_legal_moves();
    bool check_move_forward(int x, int y);
    bool check_move_right_diagonally(int x, int y);
    bool check_move_left_diagonally(int x, int y);
    vector<vector<int>> add_move_forward(vector<vector<int>> legal_moves, int x, int y);
    vector<vector<int>> add_move_right_diagonally(vector<vector<int>> legal_moves, int x, int y);
    vector<vector<int>> add_move_left_diagonally(vector<vector<int>> legal_moves, int x, int y);
    void print_board();

    Player switch_turns(Model::Player p);
private:
    vector<vector<Piece>> board_;
    Player turn_;
};

