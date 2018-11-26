// File: Exception_Handling.c
// Name: Youssef Moosa
// Synopsis: This is the definition and implementation of error handling
//           for calculator.c

// Do typical header stuff

#pragma once

// Include stdio library and define absolute value function
// as well as small epsilon variable 

#include<stdio.h>
#include<stdlib.h>
#define EPSILON 1e-20
#define abs(x) (x < 0) ? -x : x

// Function definitions

// For the power function 

void NegBaseError(const double EXPONENT)
{

  // Check if the exponent is an integer in (-x)^p
  // If it's not, then by the identity (-x)^p = (-1)^p * x^p = cis(p * pi) * x^p
  // the result is not a real number 

  if( abs( EXPONENT - (int)EXPONENT ) < EPSILON ) return;

  printf("Error: Not a real number.\n\n");
  exit(10);

}

// For if user enters 0^(arg < 0)

void zeroPowzeroError(const double BASE, const double EXPONENT)
{
    const double BASETEST = abs(BASE);
    if ( (BASETEST < EPSILON) && (EXPONENT < EPSILON) )
    {
    printf("Error: Undefined.\n\n");
    exit(20);
    }
}



// For factorial/floatorial function
// Both defined only for k > 0

void FactorialError(const int K)
{
  if (K < 0)
  {
    printf("Error: Undefined\n\n");
    exit(30);
  }
}

// For natural log function 
// Is a real number only for x > 0

void LogError(const double X)
{
  if (X < EPSILON)
  {
    printf("Error: Not a real number.\n\n");
    exit(40);
  }
}

// For arcsine/cosine functions
// Is a real number only for |x| <= 1

void ArcCircError(const double ARG)
{
  if ( abs(ARG) > 1 )
  {
    printf("Error: Not a real number.\n\n");
    exit(50);
  }
}

// For arccosh function
// Is a real number only for x > 1

void ArcCoshError(const double ARG)
{
  if ( ARG < 1 )
    {
      printf("Error: Not a real number\n\n");
      exit(60);
    }
}

// For arctanh function
// Is a real number only for |x| < 1

void ArcTanhError(const double ARG)
{
  if ( ARG >= 1 )
  {
    printf("Error: Not a real number.\n\n");
    exit(70);
  }
}

void DivByZeroError(const double DIVISOR)
{

  if( abs(DIVISOR) < EPSILON )
  {
    printf("Error: Undefined.\n\n");
    exit(80);
  }

}




