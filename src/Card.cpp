/* ---------------------------------------------------------------------------
** File: Card.cpp
** Description: Responsible for providing the Card objects used in both the
** Hand class and Deck class. Each Card has a Rank and Suit attached to it.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/Card.h"

/* No-argument Constructor */
Card::Card()
{
    //Card Rank and Suit are not initiliased.
}

/* Constructor */
Card::Card(RANK rank, SUIT suit)
{
    this->rank = rank;
    this->suit = suit;
}

/* Destructor */
Card::~Card()
{
    //Does nothing as no objects are created
    //dynamically by the constructor of this class
}

/* Returns the rank of a Card */
RANK Card::GetRank() {
	return rank;
}

/* Returns the suit of a Card */
SUIT Card::GetSuit() {
	return suit;
}

/* Converts a Card to a string representation - 2C, 3C, ... TS, JS, QS, KS, AS */
string Card::GetCardName() {
	string cardName = "";
	switch (rank) {
		case TWO   : cardName += "2"; break;
		case THREE : cardName += "3"; break;
		case FOUR  : cardName += "4"; break;
		case FIVE  : cardName += "5"; break;
		case SIX   : cardName += "6"; break;
		case SEVEN : cardName += "7"; break;
		case EIGHT : cardName += "8"; break;
		case NINE  : cardName += "9"; break;
		case TEN   : cardName += "T"; break;
		case JACK  : cardName += "J"; break;
		case QUEEN : cardName += "Q"; break;
		case KING  : cardName += "K"; break;
		case ACE   : cardName += "A"; break;
	}
	switch (suit) {
		case CLUBS    : cardName += "C"; break;
		case DIAMONDS : cardName += "D"; break;
		case HEARTS   : cardName += "H"; break;
		case SPADES   : cardName += "S"; break;
	}
	return cardName;
}
