#include "Model.hxx"
#include <vector>
#include <stdexcept>


Model::Model()
        : Model(3,3) {
}

Model::Model(int rows, int columns)
       :board_(rows * columns),
       A_{Model::Player::A},
       B_{Model::Player::B}{
    if(rows < 3 || columns < 3){
        throw std::invalid_argument("Model::Model requires a board of size more than 3 x 3");
    }
}

void Model::choose_moves(int move_number) {
}



Model::Player Model::get_winner() const {
    return {};
}

std::vector<Model::Point> Model::Player::get_pawns() const {
    return pawns_;
}
void Model::Player::MakeMove(int move) {

}

void Model::Player::set_pawns(Model::Point position) {
    Model::Player::pawns_.push_back(position);
}

void Model::Player::addMoves(Model::Point moveAvailable) {
    Model::Player::moves_available_.push_back(moveAvailable);
}

std::vector<Model::Point> Model::Player::getMoves() const {
    return moves_available_;
}


void Model::print_legal_moves() const {

}

Model::Player Model::get_currentPlayer() const {
    return {};
}

bool Model::is_game_over() const {
    return false;
}
std::vector<Model::Point> Model::get_legal_moves(const Model::Player &player) const {
    return player.getMoves();
}

bool Model::check_move_forward(Model::Point current_position) const {
    Model::OccupiedPlace next_place_ = board_[current_position.x][current_position.y + 1];
    return !(next_place_ == Model::OccupiedPlace::B || next_place_ == Model::OccupiedPlace::W);
}

bool Model::check_move_left_diagonal(Model::Point position) const {
    Model::OccupiedPlace current_position_ = board_[position.x][position.y];
    Model::OccupiedPlace left_diagonal_ = board_[position.x - 1][position.y+1];
    switch (current_position_) {
        case Model::OccupiedPlace::B :
            return left_diagonal_ == Model::OccupiedPlace::W;
        case Model::OccupiedPlace::W :
            return left_diagonal_ == Model::OccupiedPlace::B;
        default:
            throw std::invalid_argument("No Pawn at the Current Index");
    }
}

bool Model::check_move_right_diagonal(Model::Point position) const {
    Model::OccupiedPlace current_position_ = board_[position.x][position.y];
    Model::OccupiedPlace right_diagonal_ = board_[position.x + 1][position.y + 1];
    switch (current_position_) {
        case Model::OccupiedPlace::B :
            return right_diagonal_ == Model::OccupiedPlace::W;
        case Model::OccupiedPlace::W :
            return right_diagonal_ == Model::OccupiedPlace::B;
        default:
            throw std::invalid_argument("No Pawn at the Current Index");
    }
}

void Model::populate_board(int rows, int columns) {
    Model::Player playerB;
    Model::Player playerA;
    Model::OccupiedPlace B = Model::OccupiedPlace::B;
    Model::OccupiedPlace W = Model::OccupiedPlace::W;
    Model::OccupiedPlace N = Model::OccupiedPlace::N;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0) {
                board_[i][j] = B;
                Model::Point p = Point(i,j);
                playerB.set_pawns(p);
            }
            else if (i == rows - 1) {
                board_[i][j] = W;
            }
            else {
                board_[i][j] = N;
            }
        }
    }
}

void Model::set_legal_moves(Model::Player &player) {

    std::vector<Model::Point> allPawns_ = player.get_pawns();
    for(auto allPawn : allPawns_) {
        if(check_move_forward(allPawn)) {
            Model::Point p(allPawn.x, allPawn.y+1);
            player.addMoves(p);
        }
        if(check_move_right_diagonal(allPawn)) {
            Model::Point p(allPawn.x-1, allPawn.y+1);
            legalMoves_.push_back(p);
        }
        if(check_move_left_diagonal(allPawn)) {
            Model::Point p(allPawn.x+1, allPawn.y+1);
            legalMoves_.push_back(p);
        }
    }
    return legalMoves_;
}



