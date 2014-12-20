/* ---------------------------------------------------------------------------
** File: Deck.cpp
** Description: Responsible for providing an accurate array of Card objects
** that can be called upon to be added to each Hand, after being shuffled.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/Deck.h"

using namespace std;

const int NUM_SHUFFLES = 1000;

/* Constructor to create a new Deck of pointers to Card objects */
Deck::Deck() {
    cards = new Card*[CARDS_IN_DECK];
	for (int suit = 0; suit < NUM_SUITS; suit++) {
		for (int rank = 0; rank < NUM_RANKS; rank++) {
			cards[suit * NUM_RANKS + rank] = new Card((RANK)rank, (SUIT)suit);
		}
	}
    cardsDealt = 0;
}

/* Destructor to remove Card objects from Deck */
Deck::~Deck() {
    for (int i = 0; i < CARDS_IN_DECK; i++) {
        delete cards[i];
    }
    delete[] cards;
}

/* Returns the next Card to be dealt */
Card* Deck::DealNextCard() {
    return cards[cardsDealt++];
}

/* Swaps one Card pointer index with another Card pointer
    in order to shuffle each Card with different placings  */
void Swap(Card* cards[], int idx1, int idx2) {
  	Card* temp = cards[idx1];
	cards[idx1] = cards[idx2];
	cards[idx2] = temp;
}

/* Shuffles the Deck of Card pointers a number of times */
void Deck::Shuffle() {
	int idx1, idx2;
    Random rand;

	// shuffle deck NUM_SHUFFLES times
	for (int i = 0; i < NUM_SHUFFLES; i++) {
		idx1 = rand.RandomInteger(0, CARDS_IN_DECK - 1);
		idx2 = rand.RandomInteger(0, CARDS_IN_DECK - 1);
		Swap(cards, idx1, idx2);
	}
}

/* Displays the Deck with each Card object RANK and SUIT */
void Deck::DisplayDeck() {
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            cout << setw(3) << cards[i * NUM_RANKS + j]->GetCardName();
        }
        cout << endl;
    }
}


