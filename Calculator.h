// File: Calculator.c
// Name: Youssef Moosa
// Synopsis: This is a personal project in which the program calculates various functions
//           without using any cmath libraries. This calculator calculates a number up to
//           10 significant figures.

// Note that even though the calculator only counts to 10 significant figures, users can reuse values.
// This is why it calculates the value up to the full precision of the data type double instead
// of stopping at a remainder of 1e-10. Precision of double is 1e-15.

// Double is also used because it takes up the least space in memory while keeping the precision needed.

// Include personal library for exception handling

#include "Exception_Handling.h"
#pragma once

// Define mathematical constants pi & e

#define M_PI 3.14159265358979323846                               // Pi
#define M_E 2.71828182845904523536                                // Euler's number

// Function declarations

double pow(const double BASE, const int EXPONENT);
double pow(const double BASE, const double EXPONENT);
unsigned long long int factorial(const int K);
double floatorial(const int K);
double log(const double X);
double cos(const double THETA);
double sin(const double THETA);
double tan(const double THETA);
double PchooseK(const double P, const int K);
double asin(const double ARG);
double acos(const double ARG);
double atan(const double ARG);
double sinh(const double THETA);
double cosh(const double THETA);
double tanh(const double THETA);
double asinh(const double ARG);
double acosh(const double ARG);
double atanh(const double ARG);

// Function definintions

// Power function involving integers
// If exponent is negative, function returns 1 / base / base / base ... / base, -exponent times
// if exponent is positive, function returns 1 * base * base * base ... * base, exponent times

// base is the base of the function
// exponent is the exponent of the function

double pow(const double BASE, const int EXPONENT)
{

    if (EXPONENT < 0) return pow(BASE, EXPONENT + 1) / BASE;

    if (EXPONENT > 0) return pow(BASE, EXPONENT - 1) * BASE;

    return 1;

}

// Power function involving floating point exponents
// Will use the power series of e^x to help evaluate this expression
// All x^p can be expressed as e^(p * log(x))

// base is the base of the power function
// exponent is the exponent of the power function

double pow(const double BASE, const double EXPONENT)
{

  if ( BASE < 0 )
  {
    NegBaseError(EXPONENT);
    return pow( BASE, (int)(EXPONENT) );
  }

  if ( abs(BASE) <= EPSILON )
  {
    return 0;
  }

  // These 2 steps are needed to make power series an alternating series

  if ( EXPONENT > 0 )
  return 1.0 / pow(BASE, -EXPONENT);

  if ( BASE < 1 )
  return pow(1.0 / BASE, -EXPONENT);

  // b^(x + a) = b^x * b^a. This makes it so that the floating point exponent is less than 1.
  // integer exponent can easily be calculated by above function

  if ( EXPONENT < -1 )
  return pow( BASE, EXPONENT - (int)EXPONENT ) * pow( BASE, (int)EXPONENT );

  // Next, the base can be reduced to make calculating the taylor series easier
  // It never hurts to give floating point precision a bit of leniency

  if(BASE > M_E + 0.1)
  return pow(BASE / M_E, EXPONENT) * pow(M_E, EXPONENT);

  // The current kth taylor polynomial

  double sum(1);

  // Maximum remainder dependent on magnitude of term. Since terms are negative,
  // just take the negative of the terms to determine magnitude.

  for (int k = 1; pow(-EXPONENT * log(BASE), k) / factorial(k) > 1e-15; k++ )
    { 
      sum +=  pow(EXPONENT * log(BASE), k) / factorial(k);
    }

  return sum;
  
}

// Factorial functions, which returns k(k-1)(k-2)...1
// k is the argument of the factorial function

unsigned long long int factorial(const int K)
{

  FactorialError(K);

  if (K > 1) return K * factorial(K - 1);

  return 1;

}

double floatorial(const int K)
{

  FactorialError(K);
  
  if ( K > 1 ) return K * floatorial( K - 1 );

  return 1.0;

}

// Natural logarithm, defined as a function in which e^( log (x) ) = x
// Power series of arctanh( (x - 1) / (x + 1) ) will be used to determine log(x)

// x is the argument of the log function

double log(const double X)
{

  LogError(X);

  // Using properties of logarithms to reduce x's magnitude

  if (X > M_E) return log( X / M_E ) + 1;
  if (X < 1) return -log( 1 / X );
  
  double sum(0);                            // Sum for power series
  const double ARG = ( X - 1 ) / ( X + 1 ); // argument for power series

  // Power series terms of arctan(x) are always less than terms of x / 1 - x^2
  // Therefore, use that remainder to set the ceiling of this power series remainder

  for( int k = 0; pow(ARG, 2 * k + 3) / (1 - ARG * ARG) > 1e-15; k++ )
    { 
      sum += ( pow(ARG, 2 * k + 1) / (2 * k + 1) ); 
    }

  return 2 * sum;  // Remember, 2 * arctanh( arg ) = ln(x)

}

// Cosine function, which returns the x position of x^2 + y^2 = 1 after a rotation of angle theta

// Theta is the angle of the cosine function

double cos(const double THETA)
{

  // Use properties of cosine to decrease magnitude of theta and make power series easier

  if ( THETA < 0 ) return cos( -THETA );

  if ( THETA > 2 * M_PI ) return cos( THETA - (int)(THETA / 2 / M_PI) * 2 * M_PI );

  if ( THETA > 0.5 ) return cos(THETA / 2.0) * cos(THETA / 2.0) - sin(THETA / 2.0) * sin(THETA / 2.0);

  // Implement power series for low theta
  // Note that both cosine and sine are alternating series
  // Use this fact to find maximum of remainder

  double sum(1);

  for (int k = 1; pow(THETA, 2 * k) / factorial(2 * k) > 1e-15; k++)
    { 
      sum += pow(-1, k) * pow(THETA, 2 * k) / factorial(2 * k); 
    }

  return sum;
 
}

// sine function, which returns the y position of x^2 + y^2 = 1 after a rotation of angle theta

// Theta is the angle of the function

double sin(const double THETA)
{
  // Use properties of sine to decrease magnitude of theta and make power series easier

  if(THETA < 0) return -sin(-THETA);

  if ( THETA > 2 * M_PI ) return sin( THETA - (int)(THETA / 2 / M_PI) * 2 * M_PI );

  if ( THETA > 0.5 ) return 2 * sin(THETA / 2.0) * cos(THETA / 2.0);

  // Sum represents the value of the kth taylor polynomial

  double sum(THETA);

  // Implement power series for low theta
  // Note that both cosine and sine are alternating series
  // Use this fact to find maximum of remainder

  for(int k = 1; pow(THETA, 2 * k + 1) / factorial(2 * k + 1) > 1e-15; k++)
    { 
      sum += pow(-1, k) * pow(THETA, 2 * k + 1) / factorial(2 * k + 1); 
    }

  return sum;

}

// Tangent function

double tan(const double THETA) { return sin(THETA) / cos(THETA); }

// PchooseK function, defined as p(p-1)(p-2)...(p-k+1) / factorial(k)
// Using factorial function limits PchooseK too much.
// That's why the ratio between PchooseK(p, k+1) and PchooseK(p, k) is used

// p is the p of the PchooseK function
// k is the k of the PchooseK function

double PchooseK(const double P, const int K)
{
  if( K == 0 ) return 1;
  return PchooseK( P, K-1 ) * (P - K + 1) / K;
}

// Arcsine function, defined as the function in which sin( arcsin(x) ) = x

double asin(const double ARG)
{

  ArcCircError(ARG);

  if( ARG < 0 ) return -asin(-ARG);
  if( ARG > pow(2, -0.5) ) return acos( pow( 1 - ARG * ARG, 0.5) );

  double sum(0);
  
  for (int k = 0; abs(PchooseK(-0.5, k)) * pow(ARG, 2 * k + 3) / (1 - ARG * ARG) / (2 * k + 1) > 1e-15; k++)
    { 
      sum += PchooseK(-0.5, k) * pow(-1, k) * pow(ARG, 2 * k + 1) / (2 * k + 1); 
    }

  return sum;
  
}

// arccosine = pi/2 - arcsine

double acos(const double ARG) 
{
  return M_PI / 2.0 - asin(ARG); 
}

// The fun part. Arctan ( |x| ) = arccos(1 / sqrt(x^2 + 1))

double atan(const double ARG)
{
  if (ARG < 0) return -atan(-ARG);
  return acos( 1.0 / pow(ARG * ARG + 1, 0.5) );
}

double sinh(const double THETA) 
{ 
  return ( pow( M_E, THETA ) - pow( M_E, -THETA ) ) / 2.0; 
}

double cosh(const double THETA)
{
  return 1 + sinh(THETA) * sinh(THETA);
}

double tanh(const double THETA)
{
  return sinh(THETA) / cosh(THETA);
}

double asinh(const double ARG)
{
  return log( 1 + pow( 1 + ARG * ARG, 0.5 ) );
}

double acosh(const double ARG)
{
  ArcCoshError(ARG);

  return log( 1 + pow(ARG * ARG - 1, 0.5) );
}

double atanh(const double ARG)
{
  ArcTanhError(ARG);
  return log ( ( 1 + ARG ) / ( 1 - ARG ) ) / 2.0;
}




