/* ---------------------------------------------------------------------------
** File: random.h
** Description: Random class for creating unique results each game.
**
** Author: Jackson Powell - n8600571
** -------------------------------------------------------------------------*/

#ifndef _random_h
#define _random_h

class Random {

public:

    /*
     * Constructor
     * Usage: Random rand;
     */
    Random();

    /*
     * Destructor
     * Usage: implicit
     */
    ~Random();


    /*
     * Function: RandomInteger
     * Usage: n = rand.RandomInteger(low, high);
     * ------------------------------------
     * This function returns a random integer in the range low to high,
     * inclusive.
     */
    int RandomInteger(int low, int high);

private:

    /*
     * Function: Randomize
     * Usage: Randomize();
     * -------------------
     * This function initializes the random-number generator so that
     * its results are unpredictable. If this function is not called,
     * the other functions will return the same values on each run.
     */
     void Randomise();

};
#endif
