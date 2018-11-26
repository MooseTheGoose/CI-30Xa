//
//  PowerSeriesTermCorrection.cpp
//  
//
//  Created by Youssef Moosa on 11/26/18.
//
// This is a file which serves as a testing space for implementing the integer power function,
// entirely used to calculate terms within a power series.

#include <iostream>
#include <cstdlib>
#define EPSILON 1e-16
using std::endl;
using std::cout;

// Absolute value function. Measures magnitude of number in R1 rather than magnitude and direction

// ARG is its argument

double abs(const double ARG)
{
    if (ARG < 0) return -ARG;
    return ARG;
}

// Only meant to be used for power series, not the power function.
// Because of this, only small integer value considered, and 0^0 is acceptable.

// BASE is the base of the exponential
// POWER is the power of the exponential

double PowerSeriesTerm(const double BASE, const short int POWER)
{
    if( abs(BASE) <= EPSILON && POWER < 0 ) { cout << "Error" << endl; exit(0); }
    if( POWER == SHRT_MIN ) return PowerSeriesTerm(BASE, POWER + 1) / BASE;
    if( POWER < 0 ) return 1 / PowerSeriesTerm(BASE, -POWER);
    if( POWER % 2 == 0 && POWER != 0) return PowerSeriesTerm(BASE * BASE, POWER / 2);
    if( POWER > 0 ) return BASE * PowerSeriesTerm(BASE, POWER - 1);
    return 1;
}

// Testing space for functions. Works for all kinds of doubles and short integers.

int main()
{
    for(int i = SHRT_MIN; i <= SHRT_MAX; i++)
    {
        cout << PowerSeriesTerm(-1.00001, i) << endl;
    }
    return 0;
}
