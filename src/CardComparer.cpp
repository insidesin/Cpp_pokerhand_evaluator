/* ---------------------------------------------------------------------------
** File: CardComparer.h
** Description: Responsible for comparing the rank of each Card
** against another Card.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/CardComparer.h"

/*
 * Compares the two Cards by their Rank.
 * Usage: sort(cards.begin(), cards.end(), CardComparer());
 */
bool CardComparer::operator() (Card* leftCard, Card* rightCard) {
    return (leftCard->GetRank() < rightCard->GetRank());
}
