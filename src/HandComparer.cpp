/* ---------------------------------------------------------------------------
** File: HandComparer.cpp
** Description: Responsible for comparing the value of each Hand
** against another Hand.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include "../include/HandComparer.h"

/*
 * Compares the two Hands by their HandValue.
 * Usage: sort(hands.begin(), hands.end(), HandComparer());
 */
bool HandComparer::operator() (Hand* leftHand, Hand* rightHand) {
    return (leftHand->GetValue() > rightHand->GetValue());
}
