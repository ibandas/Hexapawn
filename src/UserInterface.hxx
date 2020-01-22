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

    //displays the Current Condition of Board
    void display() const ;

    //gets the user move
    void get_user_move();

    //gets current player
    std::string get_current_player() const ;

    //displays game over when stalemate happens
    //PRECONDITION : Player has no more moves left to play && He hasn't won the game.
    void display_game_over() const;

    // plays the game
    void play_game();

    //PRECONDITION: The game is over
    void display_winner() const ;

private:
    Model model_;
    std::string player1_, player2_;
    std::ostream &out_;
    std::istream &in_;

    //Prints the board
    void print_board() const ;

    //Prints the legal moves
    void print_legal_moves() const ;

    //gets the player name
    std::string const& player_name_(Model::Player) const;

};


#endif //HEXAPAWN_USERINTERFACE_H
