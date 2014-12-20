/* ---------------------------------------------------------------------------
** File: Hand.h
** Description: Responsible for each Hand object in the game. Each hand
** is allocated a specific amount of cards and a player identifier number.
** The Hand can then be used to evaluate a hand strength and hence
** a winner of each game based on their handType and handValue.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

#include "../include/CardComparer.h"
#include "../include/Card.h"

#ifndef HAND_H
#define HAND_H

enum HandType { HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT,
                 FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };

const int MAX_CARDS_IN_HAND     = 5;

const int MID_CARD              = MAX_CARDS_IN_HAND - 3;

// Standard HandType base values.
const int STRAIGHT_FLUSH_VALUE  = 8000000;
const int FOUR_OF_A_KIND_VALUE  = 7000000;
const int FULL_HOUSE_VALUE      = 6000000;
const int FLUSH_VALUE           = 5000000;
const int STRAIGHT_VALUE        = 4000000;
const int THREE_OF_A_KIND_VALUE = 3000000;
const int TWO_PAIRS_VALUE       = 2000000;
const int ONE_PAIR_VALUE        = 1000000;

//Allows for Ranks to hold different values
//dependant on their place in the hand.
const int RANK_MODIFIER         = 13;

class Hand
{
    public:

        /*
         * Constructer to create new Hand object,
         * each hand has a different player Identity.
         * Usage: hands[i] = new Hand(i);
         */
        Hand(int playerId);

        /*
         * Destructor to remove all Card pointers
         * from Hand and clear the vector.
         */
        ~Hand();

        /*
         * Gets the handValue of a Hand.
         * Usage: Hand->GetValue();
         */
        int GetValue();

        /*
         * Gets the handType of a Hand.
         * Usage: Hand->GetHandType();
         */
        HandType GetHandType();

        /*
         * Allows Card pointers to be added to the Hand.
         * Usage: hands[i]->AddCard(card);
         */
        void AddCard(Card*);

        /*
         * Allows for Hands to be evaluated individually
         * and then tested for their handType and handValue.
         * Usage: hands[i]->Evaluate();
         */
        void Evaluate();

        /*
         * Creates a string representation of a Hand to output its
         * player identifier, its Card objects and a string
         * representation of its HandType.
         * Usage: cout << hands[i]->ToString();
         */
        string ToString();

    protected:
    private:

        /*
         * A vector of pointers to Card.
         */
        vector<Card*> cards;

        /*
         * The player identifier for the Hand.
         */
        int playerId;

        /*
         * The type of Hand that the Cards make up.
         */
        HandType handType;

        /*
         * Value of the Hand for winning strength.
         */
        int handValue;

        /*
         * Variables to place each card of the hand into
         * for easier understanding of future methods.
         */
        int cardOneRank;
        int cardTwoRank;
        int cardThreeRank;
        int cardFourRank;
        int cardFiveRank;

        /*
         * Tests to see if Hand is a One Pair.
         * returns true if Hand holds One Pair.
         * Usage: if(IsPair())
         */
        bool IsPair();

        /*
         * Tests to see if Hand is a Two Pair.
         * returns true if Hand holds Two Pairs.
         * Usage: if(IsTwoPair())
         */
        bool IsTwoPair();

        /*
         * Tests to see if Hand is a Three of a Kind.
         * returns true if Hand holds Three identical Cards.
         * Usage: if(IsThreeOfAKind())
         */
        bool IsThreeOfAKind();

        /*
         * Tests to see if Hand is a Flush.
         * returns true if Hand holds Five Cards of same Suit.
         * Usage: if(IsFlush())
         */
        bool IsFlush();

        /*
         * Tests to see if Hand is a Straight.
         * returns true if Hand holds Five Cards in order.
         * Usage: if(IsStraight())
         */
        bool IsStraight();

        /*
         * Tests to see if Hand is a Four of a Kind.
         * returns true if Hand holds Four identical Cards.
         * Usage: if(IsFourOfAKind())
         */
        bool IsFourOfAKind();

        /*
         * Provides a handValue if handType is a StraightFlush.
         * Usage: handValue = ValueStraightFlush();
         */
        int ValueStraightFlush();

        /*
         * Provides a handValue if handType is a Four of a Kind.
         * Usage: handValue = ValueFourOfAKind();
         */
        int ValueFourOfAKind();

        /*
         * Provides a handValue if handType is a Full House.
         * Usage: handValue = ValueFullHouse();
         */
        int ValueFullHouse();

        /*
         * Provides a handValue if handType is a Flush.
         * Usage: handValue = ValueFlush();
         */
        int ValueFlush();

        /*
         * Provides a handValue if handType is a Straight.
         * Usage: handValue = ValueStraight();
         */
        int ValueStraight();

        /*
         * Provides a handValue if handType is a Three of a Kind.
         * Usage: handValue = ValueThreeOfAKind();
         */
        int ValueThreeOfAKind();

        /*
         * Provides a handValue if handType is a Two Pair.
         * Usage: handValue = ValueTwoPair();
         */
        int ValueTwoPair();

        /*
         * Provides a handValue if handType is a One Pair.
         * Usage: handValue = ValueOnePair();
         */
        int ValueOnePair();

        /*
         * Provides a handValue for any handType that does
         * not come under one of the other rankings, it is
         * also used to rank equal handTypes by their Cards.
         * Usage: handValue = ValueHighCard();
         */
        int ValueHighCard();

        /*
         * Sorts the Cards in Hand based on the CardComparer class.
         * The CardComparer class sorts by Card Ranks.
         * Usage: SortCards();
         */
        void SortCards();

        /*
         * Gets a string representation of the handType.
         * Usage: handTypeName = GetHandTypeName();
         */
        string GetHandTypeName(HandType);
};

#endif // HAND_H
