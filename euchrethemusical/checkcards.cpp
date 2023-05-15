#ifndef checkcards
#define CHECKCARDS  
#include "checkcards.h"
#include "deck.h"




cardChecker::cardChecker(card trump, std::vector<card>& table) : trump(trump), bench(table) {

}

void cardChecker::setars(card trump, std::vector<card>& table) {
    this->trump = trump;
    this->bench = table;
};

card cardChecker::winningCard() {

    card winner = bench[0];
    std::string leadingSuit = bench[0].Suit;

    
    for (int i = 0; i < bench.size(); i++) {
        if (bench[i].Suit == trump.Suit && bench[i].Suit == "jack") {
            return bench[i];
        }
    }
    //bower a 
    std::string bower = gBower();
    for (int i = 0; i < bench.size(); i++) {
        if (bench[i].Suit == bower && bench[i].Suit == "jack") {
            return bench[i];
        }
    }

    //check if there are any trump suits
    if (hasTrump()) {
        //check highest card of trump suits
        for (int i = 0; i < bench.size(); i++) {
            if (bench[i].Suit == trump.Suit) {
                if (winner.Suit == trump.Suit) {
                    if (bench[i].Value < winner.Value) {
                        winner = bench[i];
                    }
                }
                else {
                    winner = bench[i];
                }
            }
        }
    }
    else {
        //check highest of leading suit
        for (int i = 0; i < bench.size(); i++) {
            if (bench[i].Suit == leadingSuit && bench[i].Value < winner.Value) {
                winner = bench[i];
            }
        }
    }
    return winner;
};

bool cardChecker::hasTrump() {

    for (int i = 0; i < bench.size(); i++) {
        if (bench[i].Suit == trump.Suit) {
            return true;
        }
    }
    return false;
}

std::string cardChecker::gBower() {
    if (trump.Suit == "hearts") {
        return "diamonds";
    }
    if (trump.Suit == "diamonds") {
        return "hearts";
    }
    if (trump.Suit == "spades") {
        return "clubs";
    }
    if (trump.Suit == "clubs") {
        return "spades";
    }
    return "none";
}

std::string cardChecker::printBench(std::vector<card> b)
{
    return std::string();
}

std::string cardChecker::printbench(std::vector<card> b) {

    std::string Bench = "\n";
    Bench += "Bench\n";
    for (int i = 0; i < b.size(); i++) {
        Bench += b[i].ShowCard();
        Bench += "\n";
    }
    return Bench;

    // before you question my choices on benches instead of using a flatter surface like a table, at my high school
    //they used to play cards at the lunch tables so sometimes it would be on the actual bench or the table and other
    //times it would be on the floor and I used to play cards on my bed
}



#endif

