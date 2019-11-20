//
// Created by madha on 20-11-2019.
//

#ifndef HEXAPAWN_USERINTERFACE_H
#define HEXAPAWN_USERINTERFACE_H


#include <string>
#include "Model.hxx"

class UserInterface {

public:

    UserInterface(Model model);
    UserInterface(Model model_,std::string player1_,std::string player2_, istream &is, ostream &os);
    void print_board();
    void set_player_names();
    void print_legal_moves();
    void display_welcome();
    void get_user_move(); // confirm move?

    //PRECONDITION: The game is over
    void display_winner();

private:
    Model model_;
    std::string player1_, player2_;
    std::ostream &out_;
    std::istream &in_;

    std::string const& player_name_(Model::Player) const;

};


#endif //HEXAPAWN_USERINTERFACE_H
