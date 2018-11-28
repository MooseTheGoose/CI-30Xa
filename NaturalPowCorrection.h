//
//  NaturalPowCorrection.h
//  
//
//  Created by Youssef Moosa on 11/27/18.
//
// This is a file which contains the natural power function
// entirely used to calculate terms within a power series.

#include <cstdlib>
#include <iostream>
#define EPSILON 1e-15

// Absolute value function. Measures magnitude of number in R1 rather than magnitude and direction

// ARG is its argument

double abs(const double ARG)
{
    if (ARG < 0) return -ARG;
    return ARG;
}

// Only meant to be used for power series, not the power function.
// Because of this, only small natural numbers considered

// BASE is the base of the exponential
// POWER is the power of the exponential

double NaturalPow(const double BASE, unsigned const short int POWER)
{
    if( POWER <= 0 ) { std::cout << "Error" << std::endl; exit(0); }
    if( POWER % 2 == 0 && POWER != 0) return NaturalPow(BASE * BASE, POWER / 2);
    if( POWER > 1 ) return BASE * NaturalPow(BASE, POWER - 1);
    return BASE;
}
