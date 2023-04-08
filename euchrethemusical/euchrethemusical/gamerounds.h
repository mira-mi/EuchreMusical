#ifndef GAMEROUNDS_H
#define GAMEROUNDS_H

#pragma once
#include "play.h"
#include "checkcards.h"
#include "deck.h"

class GameRound {

protected:
    //for deck and initializes it
    deck d;
    //points you have to win which is ten according to da rulez
    int pointsToWin = 10;
    //need 4 players
    play* players[4];
public:
    //basic names for team
    team team1;
    team team2;
    //no trump cards? 
    card Trump;

    int dealindex; //kinda like selected index but for dealers

     //function to play in the main though it's the musical
    GameRound(deck& deck);

    void PrintPlayerHands();
   // void gameRound(team1("team1"), team2("team2"));

    //void Showplayhands();
    //plays the round and loops it
    void playround();
    //game standards
    void playGame();
    //deals the cards as a dealer
    void dealingcards();
    //ends game after someone reaches 10
    bool gameEnded();
    //more trump cards
    card trumpCard();
    ////keep trump card
    bool ktrumpCard(card trump);
    //determine the winner of the round
    void dWinner(card trump, std::vector<card> bench);
    //moar bench
    std::vector<card> getBench();
    //gets new dealer so it's random
    void newDealer();
    //resets
    void rhoser();
};

#endif // !GAMEROUNDS_H