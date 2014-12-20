/* ---------------------------------------------------------------------------
** File: random.cpp
** Description: Random class for creating unique results each game.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#include <cstdlib>
#include <ctime>
#include "../include/random.h"

/*
 * Constructor
 * Usage: Random rand;
 */
Random::Random() {
    Randomise();
}

/*
 * Destructor
 * Usage: implicit
 */
Random::~Random() {
    // do nothing
}

/*
 * Function: RandomInteger
 * Usage: n = rand.RandomInteger(low, high);
 * ------------------------------------
 * This function returns a random integer in the range low to high,
 * inclusive.
 */
int Random::RandomInteger(int low, int high) {
   double d = double(rand()) / (double(RAND_MAX) + 1);
   int k = int(d * (high - low  + 1));
   return low + k;
}

/*
 * Function: Randomize
 * Usage: Randomize();
 * -------------------
 * This function initializes the random-number generator so that
 * its results are unpredictable. If this function is not called,
 * the other functions will return the same values on each run.
 */
void Random::Randomise() {
	srand(int(time(NULL)));
}

