# Euchre Musical
## (It's Just Euchre, But I'm Dramatic)

This is for my Program 420 class also know as C++ 2. I was tasked with making a bot that could play against other bots as well as play until a team reaches 10 points.
- use file named [musicL](https://github.com/mira-mi/EuchreMusical/tree/main/biddingmusicL/euchrethemusical) for the game.
 
Here are the rules for the game below.
- Play Euchre with 4 players split into teams of 2. Use a deck of cards with the aces, kings, queens, jacks, 10s, and 9s of each suit.
- Rounds last for 5 turns, or “tricks.” Each turn, players place 1 card down on the table. The card with the highest value wins the trick.
- Score points for your team if you win a majority of the tricks during a round.
- Win the game if your team is the first to earn 10 points.

These is the rules for my class.

project requirements:

- Your solution must build with cmake
- Your solution must be hosted on github
- You can use whatever editor/compiler you want just let me know how to compile it in a README.md file in the root of your project

implementation:
- You must implement game setup of 4 players
- you must initialize a standard 28 card euchre deck 
- Your eucher deck cannot be passed by value
- You must partition 4 players into 2 teams.
- Each players gets 2 cards in the first deal and 3 cards in the second.
- During the bidding phase if no player calls trump then the round ends and redeal (didn't work)
- Players cannot go all-in (couldn't get that working right even with looking at other all in codes)
- Each won hand is 1 point. play uniil a team has won 10 points
- Calling trump and losing the hand results in a lost point

The compiler I used was a linux provided on Visual Studio 2022 as a download because Visual Studio Code wouldn't download cMake or allow for Makefiles. I haven't figured out why yet but I have been debugging the problem on my laptop. 

Forgot some comments in my code that I'll add here:
- I used geeks for geeks to help with the player problems.
- I also used the card game "Go Fish" to help me fix some deck problems I was having.

## New Update
- User input for team 1, sadly team 2 hasn't gotten that far. (the're a little basic)
- More comments and new ideas 
- The file known as [musicL](https://github.com/mira-mi/EuchreMusical/tree/main/biddingmusicL/euchrethemusical) is the one that should be used. If you click the file name in the text above you can go to the folder (also included in the top)
- So, in short, when you get to the bidding phase to actual get to the phases, you have to put in 'no' to go all the way through while 'yes' will result in an immediate shut down and no points will go through.
- I am debugging the issue though
