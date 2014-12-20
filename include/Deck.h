/* ---------------------------------------------------------------------------
** File: Deck.h
** Description: Responsible for providing an accurate array of Card objects
** that can be called upon to be added to each Hand, after being shuffled.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>

#include "../include/Card.h"
#include "../include/random.h"

#ifndef DECK_H
#define DECK_H

const int CARDS_IN_DECK = 52;
const int NUM_SUITS = 4;
const int NUM_RANKS = 13;

class Deck {
    public:
        /* Constructor to create a new Deck of pointers to Card objects */
        Deck();

        /* Destructor to remove Card objects from Deck */
        ~Deck();

        /* Returns the next Card to be dealt */
        Card* DealNextCard();

        /* Shuffles the Deck of Card pointers a number of times */
        void Shuffle();

        /* Displays the Deck with each Card object RANK and SUIT */
        void DisplayDeck();

    private:
        /* A dynamic array of pointers to object Card */
        Card** cards;

        /* Keeps count of the amount of cards already dealt */
        int cardsDealt;

};

#endif
