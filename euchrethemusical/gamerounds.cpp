#ifndef GAMEROUND
#define GAMEROUND

#include "gamerounds.h"
#include "play.h"
#include <vector>
#include <algorithm>
#include "deck.h"
#include <iostream>
//using namespace std::ctype;
// my initiators were wrong
//using namespace GameRound;


 GameRound::GameRound(deck& deck) : team1("TEAM 1"), team2("TEAM 2")
{ 
        d = deck;
        dealindex = 0;
        players[0] = &team1.player1;
        players[1] = &team1.player2;
        players[2] = &team2.player1;
            players[3] = &team2.player2;
        playGame();
 }

 //From: "B.K.Bullock" ascii art
void GameRound::PrintPlayerHands() {
    std::cout << "trump card: " << Trump.ShowCard() << std::endl;
    std::cout << R"(  
       /\
     .'  `.
    '      `.
 .'          `.
{              }
 ~-...-||-...-~
       ||
      '--`)" << '\n';
    team1.ShowHands();
    team2.ShowHands();
}

void GameRound::playGame() {
    while (!gameEnded()) {
        playround();
    }
}

bool GameRound::gameEnded() {
    if (team1.points >= pointsToWin) {
        return true;
    }
    if (team2.points >= pointsToWin) {
        return true;
    }
    return false;
}

card GameRound::trumpCard()
{

    return d.PickCard();
}

bool GameRound::ktrumpCard(card trump)
{
    int cardindex = dealindex;
    for (int i = 0; i < 4; i++) {
        cardindex++;
            if (cardindex > 3) {
                cardindex = 0;
            }
            if (players[cardindex]->keept(trump)) {
                return true;
            }
    }
    return false;
}
//found on https://ascii.co.uk/art/cards
void GameRound::dWinner(card trump, std::vector<card> bench)
{
    cardChecker c = cardChecker(trump, bench);
    std::cout << c.printBench(bench) << std::endl;
    card winner = c.winningCard();
    std::cout << R"(   
                                      .------.
                   .------.           |A .   |
                   |A_  _ |    .------; / \  |
                   |( \/ )|-----. _   |(_,_) |
                   | \  / | /\  |( )  |  I  A|
                   |  \/ A|/  \ |_x_) |------'
                   `-----+'\  / | Y  A|
                         |  \/ A|-----'    hjw
                         `------')" << '\n';
    std::cout << "winner" << winner.ShowCard() << std::endl;

    if (team1.thcard(winner)) {
        team1.points++;
        team2.pointslossbyteams();
    }
     if (team2.thcard(winner)) {
        team2.points++;
        team1.pointslossbyteams();
    }

    std::cout << "team 1 has: " << team1.points << std::endl;
    std::cout << "team 2 has: " << team2.points << std::endl;
     
}

std::vector<card> GameRound::getBench()
{

    std::vector<card> bench;
   bench.push_back(players[dealindex]->playc());
   if (&team1.player1 == players[dealindex])
   {
       bench.push_back(team1.player1.playc());
   }
   if (&team1.player2 == players[dealindex])
   {
       bench.push_back(team1.player2.playc());
   }
   if (&team2.player2 == players[dealindex])
   {
       bench.push_back(team2.player2.playc());
   }
   if (&team2.player1 == players[dealindex])
   {
       bench.push_back(team2.player1.playc());
   }
   return bench;

        
}
//ascii art generator https://ascii.co.uk/art/cards
void GameRound::playround() {
    std::cout << "" << std::endl;
    std::cout << "round started" << std::endl;
    std::cout << R"(
                     .------.------.------.------.
                     |A_  _ |A /\  |A _   |A .   |
                     |( \/ )| /  \ | ( )  | / \  |
                     | \  / | \  / |(_x_) |(_,_) |
                     |  \/ A|  \/ A|  Y  A|  I  A|
                     `------^------^------'------' hjw)" << '\n';
    std::cout << "The dealer this round is player " << players[dealindex]->playn << " on team " << players[dealindex]->teamn << std::endl;
    d.Rdeck();
    d.Shuffle();
    dealingcards();
    Trump = trumpCard();
    PrintPlayerHands();
    std::cout << "round officially ended" << std::endl;
    if (!ktrumpCard(Trump)) {
        std::cout << "round failed" << std::endl;
        //not the complier telling me I can't spell 
        return;
    }
    //PrintPlayerHands();
    //this one was broken, ignore
    std::vector<card> table = getBench();
    dWinner(Trump, table);
    newDealer();
    rhoser();
    std::cout << "round officially ended" << std::endl;
}





void GameRound::newDealer()
{
    if (players[dealindex] == &team1.player1) {
        dealindex = 0;
        return;
    }
    if (players[dealindex] == &team1.player2) {
        dealindex = 1;
        return;
    }
    if (players[dealindex] == &team2.player1) {
        dealindex = 2;
        return;
    }
    if (players[dealindex] == &team2.player2) {
        dealindex = 3;
        return;
    }

}

void GameRound::rhoser() {
    for (int i = 0; i < 4; i++) {
        players[i]->ctrump = false;
    }
}

void GameRound::dealingcards() {
    team1.dealtcard(d);
    team2.dealtcard(d);
}
#endif

void PrintPlayerHands()
{
    //i don't know why this is here, but i'm afraid to get rid of it
}
