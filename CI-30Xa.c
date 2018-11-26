#include "Calculator.h"

double mem, arg1, arg2;  // Arguments
int choice1, choice2;    // Choices in menu

// NOTE: This file cannot be compiled using the gcc command in the terminal
// Instead, use g++


int main()
{
    
  // Give user choice about what category of functions user wants

  printf("1.) Arithmetic\n");
  printf("2.) Exponential/Logaritmic Functions\n");
  printf("3.) Factorial\n");
  printf("4.) Circular Functions\n");
  printf("5.) Hyperbolic Functions\n");
  printf("6.) PchooseK\n");
  printf("7.) Quit\n\n");

  // Receive input and put in newline

  scanf(" %d", &choice1);
  putchar('\n');

  // If choice user made is unclear, ask again

  if(choice1 < 1 || choice1 > 7) return main();

  // If the choice is factorial or PchooseK, Ask for argument(s)
  // and calculate immediately

  switch(choice1)
  {
    // Factorial 

    case 3:
    printf("Argument: ");
    scanf("%lf", &arg1);
    putchar('\n');
    mem = floatorial( (int)arg1 );
    printf( "factorial(%d) = %.10G\n\n", (int)arg1, mem );
    return main();

    // PchooseK

    case 6:
    printf("Argument 1: ");
    scanf(" %lf", &arg1);
    printf("Argument 2: ");
    scanf(" %lf", &arg2);
    putchar('\n');
    mem = PchooseK(arg1, (int)arg2);
    printf("PchooseK(%.10G, %d) = %.10G\n\n", arg1, (int)arg2, mem);
    return main();

    // Quit program

    case 7:
    exit(0);

  }

  // Otherwise, ask for specific functions in each category
  // and calculate from there

  switch(choice1)
  {

    // Arithmetic
  
    case 1:
    printf("1.) +\n");
    printf("2.) -\n");
    printf("3.) *\n");
    printf("4.) /\n\n");
    scanf(" %d", &choice2);
    putchar('\n');

    if(choice2 < 1 || choice2 > 4) return main();

    // Ask for arguments

    printf("Argument 1: ");
    scanf(" %lf", &arg1);
    printf("Argument 2: ");
    scanf(" %lf", &arg2);
    
    switch(choice2)
    {

      // Addition

      case 1:
      mem = arg1 + arg2;
      printf("%.10G + %.10G = %.10G\n\n", arg1, arg2, mem);
      return main();

      // Subtraction

      case 2:
      mem = arg1 - arg2;
      printf("%.10G - %.10G = %.10G\n\n", arg1, arg2, mem);
      return main();

      // Multiplication

      case 3:
      mem = arg1 * arg2;
      printf("%.10G * %.10G = %.10G\n\n", arg1, arg2, mem);
      return main();

      // Division

      case 4:
      DivByZeroError(arg2);
      mem = arg1 / arg2;
      printf("%.10G / %.10G = %.10G\n\n", arg1, arg2, mem);
      return main();

      default:
      return main();
    }

    // Exponentials and Logarithms

    case 2:
    printf("1.) x^p\n");
    printf("2.) logX(y)\n\n");
    scanf(" %d", &choice2);
    putchar('\n');
    if(choice2 < 1 || choice2 > 2) return main();

    switch(choice2)
    {
      // Powers 

      case 1:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      printf("Argument 2: ");
      scanf(" %lf", &arg2);
      putchar('\n');
      zeroPowzeroError(arg1, arg2);
      mem = pow(arg1, arg2);
      printf("%.10G^%.10G = %.10G\n\n", arg1, arg2, mem);
      return main();

      // Logarithms

      case 2:
      printf("Base: ");
      scanf(" %lf", &arg1);
      printf("Argument: ");
      scanf(" %lf", &arg2);
      putchar('\n');
      DivByZeroError ( log(arg1) );
      mem = log(arg2) / log(arg1);
      printf("log(%.10G)(%.10G) = %.10G\n\n", arg1, arg2, mem);
      return main();

      default:
      return main();  
    }

    // Trigonometry

    case 4:
    printf("1.) sin\n");
    printf("2.) cos\n");
    printf("3.) tan\n");
    printf("4.) asin\n");
    printf("5.) acos\n");
    printf("6.) atan\n\n");
    scanf(" %d", &choice2);
    putchar('\n');

    if (choice2 < 1 || choice2 > 6) return main();

    switch(choice2)
    {
      // Sin

      case 1:
      
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = sin(arg1);
      printf("sin(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Cos

      case 2:

      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = cos(arg1);
      printf("cos(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Tan

      case 3:

      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      DivByZeroError( cos(arg1) );
      mem = tan(arg1);
      printf("tan(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arcsin

      case 4:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = asin(arg1);
      printf("asin(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arccos

      case 5:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = acos(arg1);
      printf("acos(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arctan

      case 6:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = atan(arg1);
      printf("atan(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      default:
      return main();

    }

    // Hyperbolic Geometry

    case 5:
    printf("1.) sinh\n");
    printf("2.) cosh\n");
    printf("3.) tanh\n");
    printf("4.) asinh\n");
    printf("5.) acosh\n");
    printf("6.) atanh\n\n");
    scanf(" %d", &choice2);
    putchar('\n');

    if(choice2 < 1 || choice2 > 6) return main();
    
    switch(choice2)
    {
      // Sinh 

      case 1:
      
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = sinh(arg1);
      printf("sinh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Cosh

      case 2:

      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = cosh(arg1);
      printf("cosh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Tanh

      case 3:

      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = tanh(arg1);
      printf("tanh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arcsinh

      case 4:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = asinh(arg1);
      printf("asinh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arccosh

      case 5:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = acosh(arg1);
      printf("acosh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      // Arctanh

      case 6:
      printf("Argument 1: ");
      scanf(" %lf", &arg1);
      putchar('\n');
      mem = atanh(arg1);
      printf("atanh(%.10G) = %.10G\n\n", arg1, mem);
      return main();

      default:
      return main();

    }

  }

}
