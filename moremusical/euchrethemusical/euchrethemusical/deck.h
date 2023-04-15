#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

class card {
public:
	//gotta have suits and ranks
	std::string Suit;
	std::string Rank;
	//and their values
	int Value;
	//shows card as string instead of int
	//it's better that way
	std::string ShowCard();
};

class deck {
	//protected works better than private when using the header files
protected:
	//used a 24 deck, not using 7s or 8s
	std::string ranks[7] = { "eight","nine", "ten", "king", "queen", "jack", "ace" };
	std::string suits[4] = { "hearts", "diamonds", "clubs", "spades" };
	//makes deck show
	std::vector<card> ProduceDeck();
	
	std::vector<card> cards;

public:
	//shows deck
	void Deck();
	//puts deck together
	void MakeADeck();
	//shuffles
	void Shuffle();
	//picks card
	card PickCard();
	//reshuffles deck
	void Rdeck();
};

#endif // !DECK_H