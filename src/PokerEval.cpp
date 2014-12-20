/* ---------------------------------------------------------------------------
** File: PokerEval.cpp
** Description: Provides a means of playing the game through a main
** segment of code that calls all other functions of the game.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "../include/random.h"
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/HandComparer.h"

using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;

int main(int argc, char *argv[]) {

    // Declare Deck and vector of pointer to Hand
    Deck deck = Deck();
    vector<Hand*> hands(PLAYERS);

    // Create Hand objects for each player
    for(int i = 0; i < PLAYERS; i++) {
        hands[i] = new Hand(i);
    }

    // allow for testing from file
    if (argc == 2) {

        // open the file and check it exists
        ifstream infile;
        infile.open(argv[1]);
        if (infile.fail()) {
            cerr <<  "Error: Could not find file" << endl;
            return 1;
        }

        // read the cards into the hands
        int rank, suit;
        for (int card = 0; card < CARDS_PER_PLAYER; card++) {
            for (int i = 0; i < PLAYERS; i++) {
                infile >> rank >> suit;
                Card *card = new Card((RANK)rank, (SUIT)suit);
                hands[i]->AddCard(card);
            }
        }

        // close the file
        infile.close();
    } else {

        // Shuffle the deck
        deck.Shuffle();

        // Deals a card to each player from the shuffled deck
        for(int i = 0; i < PLAYERS; i++) {
            for(int x = 0; x < CARDS_PER_PLAYER; x++) {
                Card *card = deck.DealNextCard();
                hands[i]->AddCard(card);
            }
        }

    }

    // Evaluate the strength of each player's Hand
    for(int i = 0; i < PLAYERS; i++) {
        hands[i]->Evaluate();
    }

    // Sort by the strength value of each player
    sort(hands.begin(), hands.end(), HandComparer());

    // Display the Hands to the console, highest hand wins
    for(int i = 0; i < PLAYERS; i++) {
        cout << hands[i]->ToString() << endl;
    }

    return 0;

}
