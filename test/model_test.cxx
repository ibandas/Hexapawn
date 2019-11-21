#include "Model.hxx"
#include <vector>
#include <catch.h>

TEST_CASE("Construct default Model")
{
    Model m;
}

TEST_CASE("Construct custom 5x5 Model")
{
    Model m(5,5);
    CHECK(m.get_board_row_size() == 5);
    CHECK(m.get_board_column_size() == 5);
}

TEST_CASE("Construct custom 3x8 Model")
{
    Model m(3,8);
    CHECK(m.get_board_row_size() == 3);
    CHECK(m.get_board_column_size() == 8);
}
TEST_CASE("Construct custom 8x3 Model")
{
    Model m(8,3);
    CHECK(m.get_board_row_size() == 8);
    CHECK(m.get_board_column_size() == 3);
}

TEST_CASE("Construct Bad Model")
{
   CHECK_THROWS_AS((Model(5,2)),std::invalid_argument);
   CHECK_THROWS_AS((Model(2,2)),std::invalid_argument);
   CHECK_THROWS_AS((Model(1,5)),std::invalid_argument);
}

TEST_CASE("Initial Player is B")
{
    Model m;
    CHECK(m.current_player() == Model::Player::B);
}

TEST_CASE("Test Run on 3x3 Board")
{
    Model m;
//    vector<Model::Move> black_legal_moves =
//            {Model::Move(Model::Point(2, 0), Model::Point(1, 0)),
//             Model::Move(Model::Point(2, 1), Model::Point(1, 1)),
//             Model::Move(Model::Point(2, 2), Model::Point(1, 2))};
//    vector<Model::Move> black_legal_moves_test = m.get_legal_moves();
//    CHECK(black_legal_moves == black_legal_moves_test);

    // Move 1
    CHECK(m.current_player() == Model::Player::B);
    Model::Piece piece1 = m.get_piece_at(Model::Point(1, 0));
    CHECK(piece1 == Model::Piece::Empty);
    m.move_choice(1);
    piece1 = m.get_piece_at(Model::Point(1, 0));
    CHECK(piece1 == Model::Piece::Black);

    // Move 2
    CHECK(m.current_player() == Model::Player::W);
    Model::Piece piece2 = m.get_piece_at(Model::Point(0, 1));
    CHECK(piece2 == Model::Piece::White);
    m.move_choice(2);
    piece2 = m.get_piece_at(Model::Point(1, 0));
    CHECK(piece2 == Model::Piece::White);

    // Move 3
    CHECK(m.current_player() == Model::Player::B);
    Model::Piece piece3 = m.get_piece_at(Model::Point(1, 1));
    CHECK(piece3 == Model::Piece::Empty);
    m.move_choice(1);
    piece3 = m.get_piece_at(Model::Point(1, 1));
    CHECK(piece3 == Model::Piece::Black);

    // Move 4
    CHECK(m.current_player() == Model::Player::W);
    Model::Piece piece4 = m.get_piece_at(Model::Point(1, 2));
    CHECK(piece4 == Model::Piece::Empty);
    m.move_choice(2);
    piece4 = m.get_piece_at(Model::Point(1, 2));
    CHECK(piece4 == Model::Piece::White);

    // Move 5
    CHECK(m.current_player() == Model::Player::B);
    Model::Piece piece5 = m.get_piece_at(Model::Point(0, 1));
    CHECK(piece5 == Model::Piece::Empty);
    m.move_choice(1);
    piece5 = m.get_piece_at(Model::Point(0, 1));
    CHECK(piece3 == Model::Piece::Black);
    CHECK(m.is_game_over());

}

