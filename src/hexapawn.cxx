#include "Model.hxx"
#include <iostream>

using namespace std;

int main()
{
    Model board = Model();
    board.print_board(std::cout);
    Model::Point p(3,0);
    Model::Point p1(2,0);
    board.print_legal_moves(std::cout);
//    board.move_pawn(p,p1);
//    board.print_board(std::cout);
//    board.print_legal_moves(std::cout);
}
