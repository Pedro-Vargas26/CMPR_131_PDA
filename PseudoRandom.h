#pragma once
#include <unordered_map>
using std::unordered_map;

class PseudoRandom
{
public:
    /*-------------------------------------------------------------------------*/
    // precondition: none
    // postcondition: initializes with default values
    PseudoRandom();
    /*-------------------------------------------------------------------------*/
    // precondition: valid positive integers for modulo, multiplier, and increment
    // postcondition: initializes generator with given parameters
    PseudoRandom(int, int, int);
    /*-------------------------------------------------------------------------*/
    // precondition: seed must have been initialized
    // postcondition: returns the next pseudorandom integer
    int getInt();
    /*-------------------------------------------------------------------------*/
    // precondition: seed must have been initialized
    // postcondition: returns the next pseudorandom double in [0,1)
    double getIndirectNext();
    /*-------------------------------------------------------------------------*/
    // precondition: nMultiplier should be > 0
    // postcondition: multiplier is updated, returns true
    bool setMultiplier(int);
    /*-------------------------------------------------------------------------*/
    // precondition: none
    // postcondition: returns the current multiplier
    int getMultiplier() const;
    /*-------------------------------------------------------------------------*/
    // precondition: modulo should be > 0
    // postcondition: modulo is updated, returns true
    bool setModulo(int modulo);
    /*-------------------------------------------------------------------------*/
    // precondition: none
    // postcondition: returns the current modulo
    int getModulo() const;
    /*-------------------------------------------------------------------------*/
    // precondition: nSeed should be >= 0
    // postcondition: seed is updated, returns true
    bool setSeed(int);
    /*-------------------------------------------------------------------------*/
    // precondition: none
    // postcondition: returns the current seed
    int getSeed() const;
    /*-------------------------------------------------------------------------*/
    // precondition: revs > 0, intervals > 0
    // postcondition: returns a map of interval -> percentage distribution
    unordered_map<int, double> uniformDistribution(int revs, int intervals = 10);
    /*-------------------------------------------------------------------------*/
    // precondition: distributions > 0, standardDev >= 0
    // postcondition: returns an approximate Gaussian-distributed random number
    //@brief returns an exception if incorrect values are entered. Otherwise it proceeds as per usual. 
    double gaussianApproximation(double median, double standardDev, int distributions);
private:
    int seed;
    int modulo;
    int multiplier;
    int increment;
    /*-------------------------------------------------------------------------*/
    // precondition: seed, multiplier, increment, modulo initialized
    // postcondition: advances seed using linear congruential formula and returns it
    int intLinearCongruence();
};
