#ifndef PLAY_H
#define PLAY_H
//#include "deck.cpp"
#include "deck.h"
#include <stdlib.h>
#pragma once

class play {
public: 
	//shows handsize as an int
	int handsize = 3;
	//team names which is basic for now
	std::string teamn;
	//player name which is basic for now
	int playn = 0;
	
	//shows how may cards as a vec
	card hand[5];
	//plays cards
	card play;
	//trump card
	bool ctrump;

	//play
	void Play(int n, std::string tn);
	//pinks the card in hands
	void PickHand(deck& deck);
	//shows hand
	void show();
	//plays card
	card playc();
	//kw
	bool keept(card trump);
};

class team {
public:
	play player1;
	play player2;
	std::string teamn;
	int points;
	//nm = name
	team(std::string nm);
	void dealtcard(deck& deck);
	void ShowHands();
	bool thcard(card card);
	void pointslossbyteams();

	
};
#endif // !PLAY_H

//when you get home make it your own girly
// it's still the complier telling me I can't spell