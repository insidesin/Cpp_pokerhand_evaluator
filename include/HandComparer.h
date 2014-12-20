/* ---------------------------------------------------------------------------
** File: HandComparer.h
** Description: Responsible for comparing the value of each Hand
** against another Hand.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#ifndef HANDCOMPARER_H
#define HANDCOMPARER_H

#include "../include/Hand.h"

class HandComparer
{
    public:
        /*
         * Compares the two Hands by their HandValue.
         * Usage: sort(hands.begin(), hands.end(), HandComparer());
         */
        bool operator() (Hand*, Hand*);
    protected:
    private:
};

#endif // HANDCOMPARER_H
