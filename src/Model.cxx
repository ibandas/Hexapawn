#include "Model.hxx"
#include <iostream>

using namespace std;

Model::Model() {
    int rows = 0;
    int columns = 0;
    while(rows < 3 || columns < 3) {
        cout << "Enter number of rows equal or greater than three: ";
        cin >> rows;
        cout << "Enter number of columns equal or greater than three: ";
        cin >> columns;
        cout << "\n";
    }
    // Initialize Player
    turn_ = Player::W;
    // Initialize board
    board_.resize(rows);
    for (int i = 0; i < rows; i++)
        board_[i].resize(columns);

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            if (x == 0) {
                board_[x][y] = Model::Piece::White;
            } else if (x == rows - 1) {
                board_[x][y] = Model::Piece::Black;
            } else {
                board_[x][y] = Model::Piece::Empty;
            }
        }
    }
}


void Model::print_board() {
    for (int row = 0; row < board_.size(); row++) {
        for (int column = 0; column < board_[row].size(); column++) {
            if (board_[row][column] == Model::Piece::White) {
                cout << "W ";
            }
            else if (board_[row][column] == Model::Piece::Black) {
                cout << "B ";
            }
            else  {
                cout << "N ";
            }
        }
        cout << "\n";
    }
}

vector<vector<int>> Model::get_legal_moves() {
    vector<vector<int>> legal_moves;
    for (int x = 0; x < board_.size(); x++) {
        for (int y = 0; y < board_[x].size(); y++) {
            if (check_move_forward(x, y)) {
                if (turn_ == Player::B) {
                    legal_moves.push_back({x, y, x-1, y});
                }
                else if (turn_ == Player::W) {
                    legal_moves.push_back({x, y, x+1, y});
                }
            }
            else if (check_move_right_diagonally(x, y)) {
                if (turn_ == Player::B) {
                    legal_moves.push_back({x, y, x-1, y+1});
                }
                else if (turn_ == Player::W) {
                    legal_moves.push_back({x, y, x+1, y-1});
                }
            }
            else if (check_move_left_diagonally(x, y)) {
                if (turn_ == Player::B) {
                    legal_moves.push_back({x, y, x-1, y-1});
                }
                else if (turn_ == Player::W) {
                    legal_moves.push_back({x, y, x+1, y+1});
                }
            }
        }
    }
    return legal_moves;
}

bool Model::check_move_forward(int x, int y) {
    //cout << board_.size();
    if (turn_ == Player::B) {
        if (x == 0) {
            return false;
        }
        else {
            if (board_[x][y] == Piece::Black && board_[x-1][y] == Piece::Empty) {
                //cout << "Here Fourth \n";
                return true;
            }
        }
    }
    else if (turn_ == Player::W) {
        // Technically might return game over here
        if (x == board_.size() - 1) {
            return false;
        }
        else {
            if (board_[x][y] == Piece::White && board_[x+1][y] == Piece::Empty) {
                return true;
            }
        }
    }
    return false;
}

bool Model::check_move_right_diagonally(int x, int y) {

    if (turn_ == Player::B) {
        if (y == board_[x].size() - 1) {
            return false;
        }
        else if (board_[x][y] == Piece::Black) {
            if (board_[x-1][y+1] == Piece::White) {
                return true;
            }
        }
    }
    else if (turn_ == Player::W) {
        if (y == 0) {
            return false;
        }
        else if (board_[x][y] == Piece::White) {
            if (board_[x+1][y-1] == Piece::Black) {
                return true;
            }
        }
    }
    return false;
}

bool Model::check_move_left_diagonally(int x, int y) {
    if (turn_ == Player::B) {
        if (y == 0) {
            return false;
        }
        else if (board_[x][y] == Piece::Black) {
            if (board_[x-1][y-1] == Piece::White) {
                return true;
            }
        }
    }
    else if (turn_ == Player::W) {
        if (y == board_[x].size() - 1) {
            return false;
        }
        else if (board_[x][y] == Piece::White) {
            if (board_[x+1][y+1] == Piece::Black) {
                return true;
            }
        }
    }
    return false;
}

Model::Player Model::switch_turns(Model::Player p) {
    if (p == Model::Player::B) {
        return Model::Player::W;
    }
    else {
        return Model::Player::B;
    }
}

void Model::print_legal_moves() {
    vector<vector<int>> legal_moves = get_legal_moves();
    for (int i = 0; i < legal_moves.size(); i++) {
        cout << "Move " << i << ": " << "(" <<
             legal_moves[i][0] << "," << legal_moves[i][1] << ")" << " to " << "(" <<
             legal_moves[i][2] << "," << legal_moves[i][3] << ")" << "\n";
    }
}
