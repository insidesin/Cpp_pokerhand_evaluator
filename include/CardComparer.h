/* ---------------------------------------------------------------------------
** File: CardComparer.h
** Description: Responsible for comparing the rank of each Card
** against another Card.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/Card.h"

#ifndef CARDCOMPARER_H
#define CARDCOMPARER_H


class CardComparer
{
    public:
        /*
         * Compares the two Cards by their Rank.
         * Usage: sort(cards.begin(), cards.end(), CardComparer());
         */
        bool operator() (Card*, Card*);
    protected:
    private:
};

#endif // CARDCOMPARER_H
