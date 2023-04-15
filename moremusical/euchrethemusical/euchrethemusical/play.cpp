#ifndef PLAY
#define PLAY
#include "play.h"
#include <string>
#include "gamerounds.h"
//there is a lot of speller errors that i keep getting yelled at for

void play::Play(int n, std::string tn) {

	playn = n++;
	//doesn't really work all that well
	teamn = tn;

};

void play::PickHand(deck& deck) {
	for (int i = 0; i < handsize; i++)
	{
		hand[i] = deck.PickCard();
	}
};

void play::show() {
	std::cout << "current player " << playn << "'s hand on team " << teamn << std::endl;
	for (int c = 0; c < handsize; c++) {
		std::cout << hand[c].ShowCard() << std::endl;
	}
};

card play::playc() {
	return hand[0];
};

bool play::keept(card trump) {
	for (int c = 0; c < handsize; c++) {
		if (hand[c].Suit == trump.Suit) {
			ctrump = true;
			return true;
		}
	}
	return false;
};

team::team(std::string name)  {
	points = 0;
	//name = x;
};

void team::dealtcard(deck& deck) {
	player1.PickHand(deck);
	player2.PickHand(deck);
}

void team::ShowHands() {
	player1.show();
	player2.show();
}

void team::pointslossbyteams() {
	if (player1.ctrump ) {
		if (points + 1 >= 0) {
			points++;
			std::cout << teamn << "gained a point" << std::endl;
		}
		else if (player2.ctrump) {
			if (points - 1 >= 0) {
				points--;
				std::cout << teamn << "loss a point" << std::endl;
			}
		}
	}
	if (player2.ctrump) {
		if (points +1 <= 0) {
			points++;
			std::cout << teamn << "gained a point" << std::endl;
		}
		else if (player1.ctrump) {
			if (points - 1 <= 0) {
				points--;
				std::cout << teamn << "loss a point" << std::endl;
			}
		}
	}
}

bool team::thcard(card card) {
	for (int i = 0; i < player1.handsize; i++) {
		if (player1.hand[i].ShowCard() == card.ShowCard()) {
			return true;
		}
	}

	for (int i = 0; i < player2.handsize; i++) {
		if (player2.hand[i].ShowCard() == card.ShowCard()) {
			return true;
		}
	}

	return false;
}


#endif // !PLAY
