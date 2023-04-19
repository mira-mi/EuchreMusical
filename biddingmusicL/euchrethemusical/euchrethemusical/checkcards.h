#ifndef CHECKCARDS_H

#define CHECKCARDS_H

#pragma once
#include "deck.h"
#include "play.h"

class cardChecker {
    //used protected for this one and for most of them
protected:
    //trump card
    card trump;
    //playing bench
    std::vector<card>& bench;

public:
    //winning card
    cardChecker(card trump, std::vector<card>& bench);
    //set variable
    void setars(card trump, std::vector<card>& bench);
    //show winning card
    card winningCard();
    //do you has trump
    bool hasTrump();
    //gets bower for card
    std::string gBower();
    //print the bench
    std::string printBench(std::vector<card> b);
    //the same thing but fancy
    std::string printbench(std::vector<card> b);

    //explanation for bench in the cpp file
};
#endif // !CHECKCARDS_H