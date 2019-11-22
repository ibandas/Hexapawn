//
// Created by madhav on 20-11-2019.
//

#define underline "\033[4m"
#define turn_off_underline "\033[0m"

#include "UserInterface.hxx"

UserInterface::UserInterface(ostream &os, istream &is)
        :out_{os},
         in_{is} {
    int rows_ = 3, columns_ = 3;
    std::string player1, player2;

    out_ << "Welcome to the world of Hexapawn!" << "\n";

    out_ << "Enter number of rows :: ";
    in_ >> rows_;
    out_ << "Enter number of columns :: ";
    in_ >> columns_;
    model_ = Model(rows_ ,columns_);

    out_ << "Enter Name of Player choosing Black :: ";
    in_ >> player1;
    player1_ = player1;

    out_ << "Enter Name of Player choosing White :: ";
    in_ >> player2;
    player2_ = player2;
}

std::string UserInterface::get_current_player() const{
    return player_name_(model_.current_player());
}

void UserInterface::print_board() const {
    cout << "\n";
    cout << "__|";
    // This loop is strictly for printing the top header for the column
    for (int z = 0; z < model_.get_board_column_size(); ++z) {
        cout << z << " ";
    }
//    cout << turn_off_underline;
    cout << "\n";
    for (int x = 0 ; x < model_.get_board_row_size(); ++x) {
        cout<< x <<" |";
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

void UserInterface::print_legal_moves() const {
    vector<Model::Move> legal_moves = model_.get_legal_moves();
    for (unsigned int i = 0; i < legal_moves.size(); i++) {
        out_ << "Move " << i + 1<< ": " << "(" <<
           legal_moves[i].current_position_.x << "," << legal_moves[i].current_position_.y << ")" << " to " << "(" <<
           legal_moves[i].final_position_.x << "," << legal_moves[i].final_position_.y << ")" << "\n";
    }
}

void UserInterface::display_winner() const {
    out_ << player_name_(model_.current_player()) << " Won! " ;
}


void UserInterface::get_user_move() {
    int moveNumber;
    out_ << "\n" << "Enter your desired move: ";
    in_ >> moveNumber;
    out_ <<"\n";
    model_.move_choice(moveNumber);
}

Model UserInterface::get_model() const {
    return model_;
}

std::string const &UserInterface::player_name_(Model::Player p) const {
    if (p == Model::Player::B) {
        return player1_;
    } else {
        return player2_;
    }
}



void UserInterface::display() const {
    print_board();
    out_ << get_current_player() << "'s Turn" << "\n";
    print_legal_moves();
}

void UserInterface::display_game_over() const {
    out_<<"Game Over No More Moves left to play";
}

void UserInterface::play_game() {
    while(!model_.is_game_over_win() && !model_.is_game_over_stalemate() ) {
        display();
        get_user_move();
    }

    if(model_.is_game_over_stalemate())
        display_game_over();

    if(model_.is_game_over_win())
        display_winner();
}

