//
// Created by madha on 20-11-2019.
//

#ifndef HEXAPAWN_USERINTERFACE_H
#define HEXAPAWN_USERINTERFACE_H


#include <string>
#include "Model.hxx"

class UserInterface {

public:

    UserInterface(ostream &os, istream& is);

    bool is_game_over() const;

    void display() const ;

    void get_user_move(); // confirm move?

    Model get_model() const;

    std::string get_current_player() const ;

    //PRECONDITION: The game is over
    void display_winner() const ;

private:
    Model model_;
    std::string player1_, player2_;
    std::ostream &out_;
    std::istream &in_;

    void print_board() const ;
    void print_legal_moves() const ;

    std::string const& player_name_(Model::Player) const;

};


#endif //HEXAPAWN_USERINTERFACE_H
