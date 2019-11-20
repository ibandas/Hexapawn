//
// Created by madha on 20-11-2019.
//

#include "UsesrInterface.h"

//std::string const &UserInterface::player_name_(Model::Player) const {
//    return <#initializer#>;
//}

void UserInterface::print_board() {
        for (int x = 0 ; x < model_.get_board_row_size(); ++x) {
            for (int y = 0; y <  model_.get_board_column_size(); ++y) {
                Model::Piece piece = model_.get_piece_at(Model::Point(x,y));
                if (piece == Model::Piece::White) {
                    out_ << "W ";
                }
                else if (piece == Model::Piece::Black) {
                    out_ << "B ";
                }
                else  {
                    out_ << "N ";
                }
            }
            out_ << "\n";
        }
    }
}

void UserInterface::set_player_names() {

}

void UserInterface::print_legal_moves() {

}

void UserInterface::display_welcome() {

}

void UserInterface::get_move() {

}

void UserInterface::display_winner() {

}

UserInterface::UserInterface(Model model)
    : model_(model),
     player1_("A"),
     player2_("B"),
     in_(std::cin),
     out_(std::cout){}

}

UserInterface::UserInterface(Model model, std::string player1, std::string player2, istream &is, ostream &os)
    : model_{model},
    player1_{player1},
    player2_{player2},
    in_(is),
    out_(os){

}
