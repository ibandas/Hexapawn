#include "Model.hxx"


void Model::choose_moves(int move_number) {

}

Model::Model() {

}

Model::Player Model::get_winner() const {
    return {};
}

Model::Player::Player() {

}

int Model::Player::get_pawns() const {
    return 0;
}

void Model::Player::MakeMove(int move) {

}

void Model::print_legal_moves() const {

}

Model::Player Model::get_currentPlayer() const {
    return {};
}

bool Model::is_game_over() const {
    return false;
}

int Model::get_legal_moves() {
    return 0;
}

bool Model::Check_MoveForward(Model::Point current_position) {
    return false;
}

bool Model::Check_MoveDiagonal(Model::Point current_position) {
    return false;
}
