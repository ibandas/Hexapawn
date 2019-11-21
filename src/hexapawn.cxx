#include "Model.hxx"
#include "UserInterface.hxx"
#include <iostream>

using namespace std;

int main()
{
    UserInterface ui = UserInterface(std::cout, std::cin);
    Model currentModel = ui.get_model();

    while(!ui.is_game_over()) {
        ui.display();
        ui.get_user_move();
    }
    ui.display_winner();

}