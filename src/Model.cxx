#include "Model.hxx"
#include <iostream>

using namespace std;

Model::Model()
   : Model(3,3){}


Model::Model(int rows, int columns) {
    if (rows < 3 || columns < 3) {
//        cout << "Enter number of rows equal or greater than three: ";
//        cin >> rows;
//        cout << "Enter number of columns equal or greater than three: ";
//        cin >> columns;
//        cout << "\n";

        throw std::invalid_argument("Model::Model requires more than 2 rows and columns");

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


//Model::Model() {
//    int rows = 0;
//    int columns = 0;
//    while(rows < 3 || columns < 3) {
//        cout << "Enter number of rows equal or greater than three: ";
//        cin >> rows;
//        cout << "Enter number of columns equal or greater than three: ";
//        cin >> columns;
//        cout << "\n";
//    }
//    // Initialize Player
//    turn_ = Player::B;
//    // Initialize board
//    board_.resize(rows);
//    for (int i = 0; i < rows; i++)
//        board_[i].resize(columns);
//
//    for (int x = 0; x < rows; x++) {
//        for (int y = 0; y < columns; y++) {
//            if (x == 0) {
//                board_[x][y] = Model::Piece::White;
//            } else if (x == rows - 1) {
//                board_[x][y] = Model::Piece::Black;
//            } else {
//                board_[x][y] = Model::Piece::Empty;
//            }
//        }
//    }
//}


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

vector<Model::Move> Model::get_legal_moves() const {
    vector<Model::Move> legal_moves;
    for(int x = 0; x < board_.size(); ++x) {
        for(int y = 0; y < board_[x].size(); ++y) {
            Point current_position = Point(x,y);
            if (check_move_forward(current_position)) {
                if (turn_ == Player::B) {
                    legal_moves.emplace_back( current_position, Point(x-1,y));
                }
                else if (turn_ == Player::W) {
                    legal_moves.emplace_back(current_position, Point(x+1, y));
                }
            }
            if (check_move_right_diagonally(current_position)) {
                if (turn_ == Player::B) {
                    legal_moves.emplace_back(current_position, Point(x-1, y+1));
                }
                else if (turn_ == Player::W) {
                    legal_moves.emplace_back(current_position, Point(x+1, y-1));
                }
            }
            if (check_move_left_diagonally(current_position)) {
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

bool Model::check_move_forward(const Point &p) const {
    if (turn_ == Player::B) {
        // Technically might return game over here
        if (p.x == 0) {
            return false;
        }
        else {
            if (board_[p.x][p.y] == Piece::Black && board_[p.x-1][p.y] == Piece::Empty) {
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
            if (board_[p.x][p.y] == Piece::White && board_[p.x+1][p.y] == Piece::Empty) {
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
        else if (board_[p.x][p.y] == Piece::White && board_[p.x+1][p.y-1] == Piece::Black) {
            return true;
        }
    }
    return false;
}

bool Model::check_move_left_diagonally(const Point &p) const{
    if (turn_ == Player::B) {
        if (p.y == 0) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::Black && board_[p.x-1][p.y-1] == Piece::White) {
            return true;
        }
    }
    else if (turn_ == Player::W) {
        if (p.y == board_[p.x].size() - 1) {
            return false;
        }
        else if (board_[p.x][p.y] == Piece::White && board_[p.x+1][p.y+1] == Piece::Black) {
            return true;
        }
    }
    return false;
}

void Model::switch_turns(Model::Player p) {
    if (p == Model::Player::B) {
        turn_ = Model::Player::W;
    }
    else {
        turn_ = Model::Player::B;
    }
}

void Model::print_legal_moves(ostream &os) const {
    vector<Move> legal_moves = get_legal_moves();
    for (unsigned int i = 0; i < legal_moves.size(); i++) {
        os << "Move " << i + 1<< ": " << "(" <<
           legal_moves[i].current_position_.x << "," << legal_moves[i].current_position_.y << ")" << " to " << "(" <<
           legal_moves[i].final_position_.x << "," << legal_moves[i].final_position_.y << ")" << "\n";
    }
}

void Model::move_pawn(Model::Point current_position_, Model::Point final_position_) {
    Model::Piece current_piece_ = board_[current_position_.x][current_position_.y];
    board_[current_position_.x][current_position_.y] = Model::Piece::Empty;
    board_[final_position_.x][final_position_.y] = current_piece_;
}


void Model::get_user_move(istream &is, ostream &os) {

    int moveNumber;
    os << "\n" << "Enter your desired move: ";
    is >> moveNumber;
    os<<"\n";

    vector<Move> availableMoves = get_legal_moves();
    if(moveNumber > availableMoves.size())
    {
        throw std::invalid_argument("Not a valid Move Number");
    }
    move_pawn(availableMoves[moveNumber-1].current_position_,availableMoves[moveNumber-1].final_position_);
}

bool Model::is_reached_end() const{
    if(turn_ == Model::Player::B){
        for(auto i : board_[0])
        {
            if(i == Model::Piece::Black)
                return true;
        }
    } else if(turn_ == Model::Player::W){
        for(auto i : board_[board_.size() - 1])
        {
            if(i == Model::Piece::White)
                return true;
        }
    }

    return false;
}

bool Model::is_game_over() const {
    return is_reached_end() || get_legal_moves().empty();
}

Model::Player Model::current_player() const {
    return turn_;
}
