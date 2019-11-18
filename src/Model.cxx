#include "Model.hxx"
#include <vector>

void Model::choose_moves(int move_number) {

}

Model::Model() {

}

Model::Player Model::get_winner() const {
    return {};
}

Model::Player::Player() {

}

std::vector<Model::Point> Model::Player::get_pawns() const {
    return 0;
}

void Model::Player::MakeMove(int move) {
    Model::Player::A;
}

void Model::print_legal_moves() const {

}

Model::Player Model::get_currentPlayer() const {
    return {};
}

bool Model::is_game_over() const {
    return false;
}

std::vector<Model::Point> Model::get_legal_moves() {
    struct Point point;
    return 0;
}

bool Model::Check_MoveForward(Model::Point current_position) {
    return false;
}

bool Model::Check_MoveDiagonal(Model::Point current_position) {
    return false;
}

void Model::create_board(int inputSize) {

    // Create a vector of vector with size
    // equal to row.
    std::vector<std::vector<Player::User>> vec(inputSize);
    Player::User A = Player::User::A;
    Player::User B = Player::User::B;
    Player::User N = Player::User::N;

    for (int i = 0; i < inputSize; i++) {
        for (int j = 0; j < inputSize; j++) {
            if (i == 0) {
                vec[i][j] = A;
            }
            else if (i == inputSize - 1) {
                vec[i][j] = B;
            }
            else {
                vec[i][j] = N;
            }
        }
    }
}