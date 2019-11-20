#include "Model.hxx"
#include <catch.h>

TEST_CASE("Construct default Model")
{
    Model m;
}

TEST_CASE("Construct custom Model")
{
    Model m(5,5);
}

TEST_CASE("Construct Bad Model")
{
   CHECK_THROWS_AS((Model{5,2}),std::invalid_argument);
   CHECK_THROWS_AS((Model{2,2}),std::invalid_argument);
   CHECK_THROWS_AS((Model{1,5}),std::invalid_argument);
}

TEST_CASE("Initial Player is B")
{
    Model m;
    CHECK(m.current_player() == Model::Player::B);
}

TEST_CASE("Switch turns")
{
    Model m;
    m.switch_turns(m.current_player());
    CHECK(m.current_player() == Model::Player::W);
}