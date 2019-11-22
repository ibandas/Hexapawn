#include "Model.hxx"
#include "UserInterface.hxx"
#include <iostream>

using namespace std;

int main()
{
    UserInterface hexapawn = UserInterface(std::cout, std::cin);
    hexapawn.play_game();
}