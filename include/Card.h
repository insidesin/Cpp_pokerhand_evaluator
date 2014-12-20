/* ---------------------------------------------------------------------------
** File: Card.h
** Description: Responsible for providing the Card objects used in both the
** Hand class and Deck class. Each Card has a Rank and Suit attached to it.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

/* Enumerations for both Ranking and Suit of a Card */
enum RANK { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum SUIT { DIAMONDS, CLUBS, HEARTS, SPADES };

class Card
{
    public:
        /* No arg constructor */
        Card();

        /* Creates a new Card from a given rank and suit */
        Card(RANK, SUIT);

        /* Destructor */
        ~Card();

        /* Returns the rank of a Card */
        RANK GetRank();

        /* Returns the suit of a Card */
        SUIT GetSuit();

        /* Converts a Card to a string representation - 2C, 3C, ... TS, JS, QS, KS, AS */
        string GetCardName();
    protected:
    private:
        RANK rank;
        SUIT suit;
};

#endif // CARD_H
