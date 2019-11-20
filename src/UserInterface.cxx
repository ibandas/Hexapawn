//
// Created by madha on 20-11-2019.
//

#include "UserInterface.hxx"

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

void UserInterface::set_player_names() {

}

void UserInterface::print_legal_moves() {
    vector<Model::Move> legal_moves = model_.get_legal_moves();
    for (unsigned int i = 0; i < legal_moves.size(); i++) {
        out_ << "Move " << i + 1<< ": " << "(" <<
           legal_moves[i].current_position_.x << "," << legal_moves[i].current_position_.y << ")" << " to " << "(" <<
           legal_moves[i].final_position_.x << "," << legal_moves[i].final_position_.y << ")" << "\n";
    }
}

void UserInterface::display_welcome() {

}

void UserInterface::get_user_move() {
    int moveNumber;
    out_ << "\n" << "Enter your desired move: ";
    in_ >> moveNumber;
    out_ <<"\n";
    model_.move_choice(moveNumber);
}

void UserInterface::display_winner() {

}

UserInterface::UserInterface(Model model)
        : model_(model),
          player1_("A"),
          player2_("B"),
          in_(std::cin),
          out_(std::cout){}


UserInterface::UserInterface(Model model, std::string player1, std::string player2, istream &is, ostream &os)
        : model_{model},
          player1_{player1},
          player2_{player2},
          in_(is),
          out_(os){

}
