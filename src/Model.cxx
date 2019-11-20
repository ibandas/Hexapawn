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
    turn_ = Player::B;
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


void Model::print_board(ostream &os) const {
    for (auto & row : board_) {
        for (auto & column : row) {
            if (column == Model::Piece::White) {
                os << "W ";
            }
            else if (column == Model::Piece::Black) {
                os << "B ";
            }
            else  {
                os << "N ";
            }
        }
        os << "\n";
    }
}

//vector<vector<int>> Model::get_legal_moves() {
//    vector<vector<int>> legal_moves;
//    for (int x = 0; x < board_.size(); x++) {
//        for (int y = 0; y < board_.size(); y++) {
//            if (check_move_forward(Point(x, y))) {
//                if (turn_ == Player::B) {
//                    legal_moves.push_back({x, y, x-1, y});
//                }
//                else if (turn_ == Player::W) {
//                    legal_moves.push_back({x, y, x+1, y});
//                }
//            }
//            else if (check_move_right_diagonally(Point(x, y))) {
//                if (turn_ == Player::B) {
//                    legal_moves.push_back({x, y, x-1, y+1});
//                }
//                else if (turn_ == Player::W) {
//                    legal_moves.push_back({x, y, x+1, y-1});
//                }
//            }
//            else if (check_move_left_diagonally(Point (x, y))) {
//                if (turn_ == Player::B) {
//                    legal_moves.push_back({x, y, x-1, y-1});
//                }
//                else if (turn_ == Player::W) {
//                    legal_moves.push_back({x, y, x+1, y+1});
//                }
//            }
//        }
//    }
//    return legal_moves;
//}
vector<Model::Move> Model::get_legal_moves() const {
    vector<Model::Move> legal_moves;
        for(int x = 0; x < board_.size(); ++x) {
            for(int y = 0; y < board_.size(); ++y) {
                Point current_position = Point(x,y);
                if (check_move_forward(current_position)) {
                    if (turn_ == Player::B) {
                        legal_moves.emplace_back( current_position, Point(x-1,y));
                    }
                    else if (turn_ == Player::W) {
                        legal_moves.emplace_back(current_position, Point(x+1, y));
                    }
                }
                else if (check_move_right_diagonally(current_position)) {
                    if (turn_ == Player::B) {
                        legal_moves.emplace_back(current_position, Point(x-1, y+1));
                    }
                    else if (turn_ == Player::W) {
                        legal_moves.emplace_back(current_position, Point(x+1, y-1));
                    }
                }
                else if (check_move_left_diagonally(current_position)) {
                    if (turn_ == Player::B) {
                        legal_moves.emplace_back(current_position, Point(x-1, y-1));
                    }
                    else if (turn_ == Player::W) {
                        legal_moves.emplace_back(current_position, Point(x+1, y+1));
                    }
                }
            }
        }
    return legal_moves;
}

//vector<vector<int>> Model::add_move_forward(vector<vector<int>> legal_moves, int x, int y) {
//    if (turn_ == Player::B) {
//        legal_moves.push_back({x, y, x-1, y});
//    }
//    else if (turn_ == Player::W) {
//        legal_moves.push_back({x, y, x+1, y});
//    }
//    return legal_moves;
//}
//
//vector<vector<int>> Model::add_move_right_diagonally(vector<vector<int>> legal_moves, int x, int y) {
//    if (turn_ == Player::B) {
//        legal_moves.push_back({x, y, x-1, y+1});
//    }
//    else if (turn_ == Player::W) {
//        legal_moves.push_back({x, y, x+1, y-1});
//    }
//    return legal_moves;
//}
//
//vector<vector<int>> Model::add_move_left_diagonally(vector<vector<int>> legal_moves, int x, int y) {
//    if (turn_ == Player::B) {
//        legal_moves.push_back({x, y, x-1, y-1});
//    }
//    else if (turn_ == Player::W) {
//        legal_moves.push_back({x, y, x+1, y+1});
//    }
//    return legal_moves;
//}




bool Model::check_move_forward(const Point &p) const {
    if (turn_ == Player::B) {
        // cout << "Here \n";
        // Technically might return game over here
        if (p.x == 0) {
            // cout << "Here Too \n";
            return false;
        }
        else {
            // cout << "Here Thrice \n";
            if (board_[p.x-1][p.y] == Piece::Empty) {
                // cout << "Here Fourth \n";
                return true;
            }
        }
    }
    else if (turn_ == Player::W) {
        // Technically might return game over here
        if (p.x == board_.size() - 1) {
            return false;
        }
        else {
            if (board_[p.x+1][p.y] == Piece::Empty) {
                return true;
            }
        }
    }
    return false;
}

bool Model::check_move_right_diagonally(const Point &p) const {

    if (turn_ == Player::B) {
        if (p.y == board_[p.x].size() - 1) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::Black && board_[p.x-1][p.y+1] == Piece::White) {
                return true;
        }
    }
    else if (turn_ == Player::W) {
        if (p.y == 0) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::White) {
            if (board_[p.x+1][p.y-1] == Piece::Black) {
                return true;
            }
        }
    }
    return false;
}

bool Model::check_move_left_diagonally(const Point &p) const{
    if (turn_ == Player::B) {
        if (p.y == 0) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::Black) {
            if (board_[p.x-1][p.y-1] == Piece::White) {
                return true;
            }
        }
    }
    else if (turn_ == Player::W) {
        if (p.y == board_[p.x].size() - 1) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::White) {
            if (board_[p.x+1][p.y+1] == Piece::Black) {
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



//void Model::print_legal_moves() {
//    vector<vector<int>> legal_moves = get_legal_moves();
//    for (int i = 0; i < legal_moves.size(); i++) {
//        cout << "Move " << i << ": " << "(" <<
//             legal_moves[i][0] << "," << legal_moves[i][1] << ")" << " to " << "(" <<
//             legal_moves[i][2] << "," << legal_moves[i][3] << ")" << "\n";
//    }
//}

void Model::print_legal_moves(ostream &os) {
    vector<Move> legal_moves = get_legal_moves();
    for (int i = 0; i < legal_moves.size(); i++) {
        os << "Move " << i << ": " << "(" <<
           legal_moves[i].current_position_.x << "," << legal_moves[i].current_position_.y << ")" << " to " << "(" <<
           legal_moves[i].final_position_.x << "," << legal_moves[i].final_position_.y << ")" << "\n";
    }
}


void Model::move_pawn(Model::Point current_position_, Model::Point final_position_) {
    Model::Piece current_piece_ = board_[current_position_.x][current_position_.y];
    board_[current_position_.x][current_position_.y] = Model::Piece::Empty;
    board_[final_position_.x][final_position_.y] = current_piece_;
}


