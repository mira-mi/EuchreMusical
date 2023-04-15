#ifndef deck
#define DECK
#include "deck.h"
#include <vector>
#include <algorithm>
#include <time.h>

std::string card::ShowCard() {
	return Rank + " of " + Suit;
}

std::vector<card> deck::ProduceDeck() {
	std::vector<card> deck;
	deck.clear();
	for (int r = 0; r < 6; r++)
	{
		for (int s = 0; s < 4; s++)
		{
			card c = card(ranks[r], suits[s], r);
			deck.push_back(c);
		}
	}
	return deck;

};

void deck::Deck()
{
	srand(time(0));
	Rdeck();
};

void deck::MakeADeck() {
	std::cout << "Making deck" << std::endl;
	for (int c = 0; c < cards.size(); c++) {
		std::cout << cards[c].ShowCard() << std::endl;
	}
};

card deck::PickCard()
{
	card c = cards[cards.size() - 1];
	cards.pop_back();
	return c;
};
void deck::Shuffle()
{
	for (size_t i = cards.size() - 1; i > 0; i--)
	{
		int n = rand() % (i + 1);

		card temp = cards[i];
		cards[i] = cards[n];
		cards[n] = temp;
	}

	//fisher yates shuffle
}

void deck::Rdeck() {
	cards = ProduceDeck();
}

#endif
