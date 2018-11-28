//
//  NaturalLogCorrection.cpp
//
//  Created by Youssef Moosa on 11/28/18.
//
// There actually wasn't much to correct. It was pretty much changing
// documentation and variable names, for the most part

#include <iostream>
#include <cstdlib>
#include <climits>
#define M_E 2.71828182845904523536
#include "NaturalPowCorrection.h"

// Function calculates the natural log of a function using
// arctanh power series and logarithmic argument reduction identities

// ARG is the argument of the function

double ln(const double ARG)
{
    // Variable declarations
    
    double taylorTerm, partialSum;
    bool remainderNotLessThanEpsilon(1);
    
    // Function Implementation
    
    // Magnitude deduction / Error detection
    
    if(ARG <= 0)   { cout << "Error" << endl; exit(0); }
    if(ARG < 1)    return -ln(1 / ARG);
    if(ARG >= M_E)  return ln(ARG / M_E) + 1;
    
    // Taylor series implementation
    
    taylorTerm = (ARG - 1) / (ARG + 1);
    partialSum = taylorTerm;
    const double PARTIAL_TERM_RATIO(taylorTerm * taylorTerm); // Not actual term ratio. Just a helper constant.
    
    for(int k = 3; remainderNotLessThanEpsilon; k += 2)
    {
        taylorTerm *= PARTIAL_TERM_RATIO * (k-2) / k;
        partialSum += taylorTerm;
        remainderNotLessThanEpsilon = ((taylorTerm * PARTIAL_TERM_RATIO) / (1 - PARTIAL_TERM_RATIO) > EPSILON);
    }
    
    return 2 * partialSum;
}
