/* ---------------------------------------------------------------------------
** File: Hand.cpp
** Description: Responsible for each Hand object in the game. Each hand
** is allocated a specific amount of cards and a player identifier number.
** The Hand can then be used to evaluate a hand strength and hence
** a winner of each game based on their handType and handValue.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/Hand.h"

/*
 * Constructer to create new Hand object,
 * each hand has a different player Identity.
 * Usage: hands[i] = new Hand(i);
 */
Hand::Hand(int playerId)
{
    this->cards = vector<Card*>();
    this->playerId = playerId;
}

/*
 * Destructor to remove all Card pointers
 * from Hand and clear the vector.
 */
Hand::~Hand()
{
    for(vector<Card*>::const_iterator i = cards.begin(); i != cards.end(); i++)
    {
        delete *i;
    }
    cards.clear();
}

/*
 * Allows Card pointers to be added to the Hand.
 * Usage: hands[i]->AddCard(card);
 */
void Hand::AddCard(Card* card) {
    if((int) cards.size() < MAX_CARDS_IN_HAND) {
        cards.push_back(card);
    }
}

/*
 * Allows for Hands to be evaluated individually
 * and then tested for their handType and handValue.
 * Usage: hands[i]->Evaluate();
 */
void Hand::Evaluate() {
    SortCards();

    //Place each card of the hand into a variable
    //for easier understanding of future methods.
    cardOneRank   = cards[0]->GetRank();
    cardTwoRank   = cards[1]->GetRank();
    cardThreeRank = cards[2]->GetRank();
    cardFourRank  = cards[3]->GetRank();
    cardFiveRank  = cards[4]->GetRank();

    //Check for each hand type.
    if(IsStraight() && IsFlush()) {
        handType = STRAIGHT_FLUSH;
        handValue = ValueStraightFlush();
    } else if(IsFourOfAKind()) {
        handType = FOUR_OF_A_KIND;
        handValue = ValueFourOfAKind();
    } else if(IsThreeOfAKind() && IsTwoPair()) {
        handType = FULL_HOUSE;
        handValue = ValueFullHouse();
    } else if(IsFlush()) {
        handType = FLUSH;
        handValue = ValueFlush();
    } else if(IsStraight()) {
        handType = STRAIGHT;
        handValue = ValueStraight();
    } else if(IsThreeOfAKind()) {
        handType = THREE_OF_A_KIND;
        handValue = ValueThreeOfAKind();
    } else if(IsTwoPair()) {
        handType = TWO_PAIR;
        handValue = ValueTwoPair();
    } else if(IsPair()) {
        handType = ONE_PAIR;
        handValue = ValueOnePair();
    } else {
        handType = HIGH_CARD;
        handValue = ValueHighCard();
    }
}

/*
 * Tests to see if Hand is a One Pair.
 * returns true if Hand holds One Pair.
 * Usage: if(IsPair())
 */
bool Hand::IsPair(){
    for(int i = 0; i < MAX_CARDS_IN_HAND - 1; i++) {
        //If current rank is the same to next Card's rank.
        if((cards[i]->GetRank()) == (cards[i + 1]->GetRank()))
            return true;
    }
    return false;
}

/*
 * Tests to see if Hand is a Two Pair.
 * returns true if Hand holds Two Pairs.
 * Usage: if(IsTwoPair())
 */
bool Hand::IsTwoPair(){
    return (((cardOneRank == cardTwoRank) &&
             (cardThreeRank == cardFourRank))
        ||  ((cardTwoRank == cardThreeRank) &&
             (cardFourRank == cardFiveRank))
        ||  ((cardOneRank == cardTwoRank) &&
             (cardFourRank == cardFiveRank)));
}

/*
 * Tests to see if Hand is a Three of a Kind.
 * returns true if Hand holds Three identical Cards.
 * Usage: if(IsThreeOfAKind())
 */
bool Hand::IsThreeOfAKind(){
    return(((cardOneRank == cardTwoRank) &&
            (cardTwoRank == cardThreeRank))
        || ((cardTwoRank == cardThreeRank) &&
            (cardThreeRank == cardFourRank))
        || ((cardThreeRank == cardFourRank) &&
            (cardFourRank == cardFiveRank)));
}

/*
 * Tests to see if Hand is a Flush.
 * returns true if Hand holds Five Cards of same Suit.
 * Usage: if(IsFlush())
 */
bool Hand::IsFlush(){
    bool isFlush = false;
    for(int i = 1; i < MAX_CARDS_IN_HAND; i++) {
        //Check to see if each Card has same Suit.
        if(cards[0]->GetSuit() == cards[i]->GetSuit())
            isFlush = true;
        else
            return false;
    }
    return isFlush;
}

/*
 * Tests to see if Hand is a Straight.
 * returns true if Hand holds Five Cards in order.
 * Usage: if(IsStraight())
 */
bool Hand::IsStraight(){
    return (((cardOneRank == cardTwoRank - 1) &&
             (cardTwoRank == cardThreeRank - 1) &&
             (cardThreeRank == cardFourRank - 1) &&
             (cardFourRank == cardFiveRank - 1))
        ||  ((cardOneRank ==  0) && (cardTwoRank == 1) &&
             (cardThreeRank == 2) && (cardFourRank == 3) &&
             (cardFiveRank == 12)));
}

/*
 * Tests to see if Hand is a Four of a Kind.
 * returns true if Hand holds Four identical Cards.
 * Usage: if(IsFourOfAKind())
 */
bool Hand::IsFourOfAKind(){
    return(((cardOneRank == cardTwoRank) &&
            (cardTwoRank == cardThreeRank) &&
            (cardThreeRank == cardFourRank))
        || ((cardTwoRank == cardThreeRank) &&
            (cardThreeRank == cardFourRank) &&
            (cardFourRank == cardFiveRank)));
}

/*
 * Provides a handValue if handType is a StraightFlush.
 * Usage: handValue = ValueStraightFlush();
 */
int Hand::ValueStraightFlush() {
    //If Ace is present, lowest StraightFlush value is used.
    if(cardOneRank == TWO && cardFiveRank == ACE)
        return STRAIGHT_FLUSH_VALUE;
    return STRAIGHT_FLUSH_VALUE + ValueHighCard();
}

/*
 * Provides a handValue if handType is a Four of a Kind.
 * Usage: handValue = ValueFourOfAKind();
 */
int Hand::ValueFourOfAKind() {
    return FOUR_OF_A_KIND_VALUE + cards[MID_CARD]->GetRank();
}

/*
 * Provides a handValue if handType is a Full House.
 * Usage: handValue = ValueFullHouse();
 */
int Hand::ValueFullHouse() {
    return FULL_HOUSE_VALUE + cards[MID_CARD]->GetRank();
}

/*
 * Provides a handValue if handType is a Flush.
 * Usage: handValue = ValueFlush();
 */
int Hand::ValueFlush() {
    return FLUSH_VALUE + ValueHighCard();
}

/*
 * Provides a handValue if handType is a Straight.
 * Usage: handValue = ValueStraight();
 */
int Hand::ValueStraight() {
    //If Ace is present, lowest Straight value is used.
    if(cardOneRank == TWO && cardFiveRank == ACE)
        return STRAIGHT_VALUE;
    return STRAIGHT_VALUE + ValueHighCard();
}

/*
 * Provides a handValue if handType is a Three of a Kind.
 * Usage: handValue = ValueThreeOfAKind();
 */
int Hand::ValueThreeOfAKind() {
    return THREE_OF_A_KIND_VALUE + cards[MID_CARD]->GetRank();
}

/*
 * Provides a handValue if handType is a Two Pair.
 * Usage: handValue = ValueTwoPair();
 */
int Hand::ValueTwoPair() {
    int value = 0;

    //Tests to see where each Pair is located and gives a
    //Hand strength based on their locations.
    if (cardOneRank == cardTwoRank && cardThreeRank == cardFourRank)
        value = pow(RANK_MODIFIER, 2)*cardThreeRank +
                pow(RANK_MODIFIER, 1)*cardOneRank + cardFiveRank;
    else if (cardOneRank == cardTwoRank && cardFourRank == cardFiveRank)
        value = pow(RANK_MODIFIER, 2)*cardFourRank +
                pow(RANK_MODIFIER, 1)*cardOneRank + cardThreeRank;
    else
        value = pow(RANK_MODIFIER, 2)*cardFourRank +
                pow(RANK_MODIFIER, 1)*cardTwoRank + cardOneRank;

    return TWO_PAIRS_VALUE + value;
}

/*
 * Provides a handValue if handType is a One Pair.
 * Usage: handValue = ValueOnePair();
 */
int Hand::ValueOnePair() {
    int value = 0;

    //Tests to see where each Pair is located and gives a
    //Hand strength based on their locations.
    if (cardOneRank == cardTwoRank)
        value = pow(RANK_MODIFIER, 3)*cardOneRank + cardThreeRank +
                pow(RANK_MODIFIER, 1)*cardFourRank + pow(RANK_MODIFIER, 2)*cardFiveRank;
    else if (cardTwoRank == cardThreeRank)
        value = pow(RANK_MODIFIER, 3)*cardTwoRank + cardOneRank +
                pow(RANK_MODIFIER, 1)*cardFourRank + pow(RANK_MODIFIER, 2)*cardFiveRank;
    else if (cardThreeRank == cardFourRank)
        value = pow(RANK_MODIFIER, 3)*cardThreeRank + cardOneRank +
                pow(RANK_MODIFIER, 1)*cardTwoRank + pow(RANK_MODIFIER, 2)*cardFiveRank;
    else
        value = pow(RANK_MODIFIER, 3)*cardFourRank + cardOneRank +
                pow(RANK_MODIFIER, 1)*cardTwoRank + pow(RANK_MODIFIER, 2)*cardThreeRank;

    return ONE_PAIR_VALUE + value;
}

/*
 * Provides a handValue for any handType that does
 * not come under one of the other rankings, it is
 * also used to rank equal handTypes by their Cards.
 * Usage: handValue = ValueHighCard();
 */
int Hand::ValueHighCard() {
    return cardOneRank +
        pow(RANK_MODIFIER, 1)*cardTwoRank +
        pow(RANK_MODIFIER, 2)*cardThreeRank +
        pow(RANK_MODIFIER, 3)*cardFourRank +
        pow(RANK_MODIFIER, 4)*cardFiveRank;
}

/*
 * Gets the handValue of a Hand.
 * Usage: Hand->GetValue();
 */
int Hand::GetValue() {
    return handValue;
}

/*
 * Gets the handType of a Hand.
 * Usage: Hand->GetHandType();
 */
HandType Hand::GetHandType() {
    return handType;
}

/*
 * Sorts the Cards in Hand based on the CardComparer class.
 * The CardComparer class sorts by Card Ranks.
 * Usage: SortCards();
 */
void Hand::SortCards() {
    sort(cards.begin(), cards.end(), CardComparer());
}

/*
 * Gets a string representation of the handType.
 * Usage: handTypeName = GetHandTypeName();
 */
string Hand::GetHandTypeName(HandType handType) {
    switch (handType) {
    case HIGH_CARD:
        return "High Card";
        break;
    case ONE_PAIR:
        return "One Pair";
        break;
    case TWO_PAIR:
        return "Two Pair";
        break;
    case THREE_OF_A_KIND:
        return "Three of a Kind";
        break;
    case STRAIGHT:
        return "Straight";
        break;
    case FLUSH:
        return "Flush";
        break;
    case FULL_HOUSE:
        return "Full House";
        break;
    case FOUR_OF_A_KIND:
        return "Four of a Kind";
        break;
    case STRAIGHT_FLUSH:
        return "Straight Flush";
        break;
    }
    return "null";
}

/*
 * Creates a string representation of a Hand to output its
 * player identifier, its Card objects and a string
 * representation of its HandType.
 * Usage: cout << hands[i]->ToString();
 */
string Hand::ToString() {
    stringstream ss; //Create a stringstream

    string finalString = "Player ";
    ss.width(2);
    ss << playerId + 1; //Add to stringstream
    finalString += ss.str() + " -"; //and place back into string.
    for(int i = 0; i < (int) cards.size(); i++) {
        finalString += " " + cards.at(i)->GetCardName();
    }
    finalString += " - " + GetHandTypeName(handType);

    return finalString;
}
