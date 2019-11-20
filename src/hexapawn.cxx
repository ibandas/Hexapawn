#include "Model.hxx"
#include <iostream>

using namespace std;

int main()
{
    Model board = Model();
    board.print_board();
    board.print_legal_moves();
}
