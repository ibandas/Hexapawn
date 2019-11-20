#include "Model.hxx"
#include "UserInterface.hxx"
#include <iostream>

using namespace std;

int main()
{
    Model board = Model();
//    while(!board.is_game_over()) {
//        board.print_board(std::cout);
//        board.print_legal_moves(std::cout);
//        board.get_user_move(std::cin, std::cout);
//        board.switch_turns(board.current_player());
//    }

    UserInterface ui = UserInterface(board);
    while(!board.is_game_over()) {
        ui.print_board();
        ui.print_legal_moves();
        ui.get_user_move();
        board.switch_turns(board.current_player());
    }
}