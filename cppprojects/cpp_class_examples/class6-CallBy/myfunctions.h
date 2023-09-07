// Copyright 2023 bhipp
// my reusable functions!!!

//          PROJECT_PATH_FILENAME_H_
#ifndef _MYFUNCTIONS_H_
#define _MYFUNCTIONS_H_

// fractorial function - prototype
int Factorial(int);

// Greatest Common Divisor
int GCD(int, int);

// Quadratic Formula :  ax^2 + bx + c
// (-b +- sqrt(b^2 - 4ac) )/ (2a)
// precondition: function will be sent the coefficent of x^2,
//               the coefficient of x, the constant coefficient
//               and two double variables to hold the resulting
//               roots of the quadratic expression
// postconditions: the function will return true if the quadratic
//                 has real roots, and modifies the fourth and
//                 fifth variables to hold those values
//                 it will return false if the quadratic has
//                 no real roots, and will leave the fourth
//                 and fifth arguments unchanged
bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2);

//function that will compute the mena of two doubles 
double Avg(double, double); 
// function that computes the mean of three doubles 
double Avg(double, double, double) ; 
// function that computes the mean of two characters 
char Avg(char, char); 

// function to find the average of 5 required test grades 
double testavg(double, double, double = 0, double = 0, double = 0); //default is 0

//recursive function  
// Fibonacci sequence 1, 1, 2, 3, 5, 8, 13, 21 - add the number before it
int Fibonacci(int n);

#endif  // _MYFUNCTIONS_H_
