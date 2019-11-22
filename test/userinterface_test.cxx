//
// Created by madhav on 21-11-2019.
//

#include "UserInterface.hxx"

#include <catch.h>
#include <sstream>
#include <stdexcept>

class User_interface_fixture {
public:
    User_interface_fixture() : ui{output, input}{}
protected:
    std::istringstream input;
    std::ostringstream output;
    UserInterface ui;
};

TEST_CASE_METHOD(User_interface_fixture, "Check Player")
{
    output.str(ui.get_current_player());
    CHECK(output.str() == ui.get_current_player());
}

TEST_CASE_METHOD(User_interface_fixture, "Welcome and Move Choice") {
    input.str("3\n 3\n M\n N\n");

    ui.display();

    CHECK(output.str() == "Welcome to the world of Hexapawn!\n"
                          "Enter number of rows :: "
                          "Enter number of columns :: "
                          "Enter Name of Player choosing Black :: "
                          "Enter Name of Player choosing White :: "
                          "W W W \n"
                          "N N N \n"
                          "B B B \n"
                          "'s Turn\n"
                          "Move 1: (2,0) to (1,0)\n"
                          "Move 2: (2,1) to (1,1)\n"
                          "Move 3: (2,2) to (1,2)\n");
}
