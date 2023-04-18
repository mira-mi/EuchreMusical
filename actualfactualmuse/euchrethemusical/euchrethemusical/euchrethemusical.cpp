// euchrethemusical.cpp : Defines the entry point for the application.
// don't question the name, it was early in the morning
//
#pragma once
#include "euchrethemusical.h"
#include "play.h"
#include <iostream>
//#include "gamerounds.cpp"
#include "checkcards.h"
#include "gamerounds.h"

//using namespace GameRound;
//using namespace GameRound;
//ignore those I was straight up struggling
//player 1 wins all of the time but player 2 wins for all of 3 rounds 
//not sure how to fix that


int main() {
   // used stackoverflow to put in some ascii art and it was so cool
    // i had no idea you could add these in here
    //used some blackjack, uno, and war tutorials for a lot of this, some on stackoverlow, microsoftdev, and cpluscplus
    //used geeks for geeks as well
    //used go fish for deck issues
    //also looked back at previous projects i did for c++ 1 to fully help with this as well
    //included user input just for team names
    std::cout << R"(                                                 
'||''''|                   '||                      
 ||  .    ... ...    ....   || ..   ... ..    ....  
 ||''|     ||  ||  .|   ''  ||' ||   ||' '' .|...|| 
 ||        ||  ||  ||       ||  ||   ||     ||      
.||.....|  '|..'|.  '|...' .||. ||. .||.     '|...' 
                                                 )" << '\n';
    std::cout << R"(Euchre is a tricking taking game for 2 teams of two. Euchre uses a deck of 24 standard playing cards (using only the 9, 10, J, Q, K, and, A). 
The objective of Euchre is for your team to win 10 points.)" << '\n';
    std::cout << "This version has 28 but there is one that has 24 on there" << std::endl;
    std::cout << "This one also has some user input for team names" << std::endl;
    std::cout << "Have fun!!" << std::endl;
    deck d = deck();
    GameRound g = GameRound(d);
    //need to initialize
    //ignore that top comment it's good now
    


   
}
