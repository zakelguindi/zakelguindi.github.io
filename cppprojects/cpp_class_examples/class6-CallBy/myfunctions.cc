// Copyright 2023 bhipp
// implement myfunctions
#include"myfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<ctime>
#include<cmath>

int Factorial(int n) {
  if ( n < 0 ) {
    cout << "Factorial is not defined for negative integers"
         << endl;
    return 0;
  }
  int answer = 1;
  for ( int i = 2; i<= n; ++i )
    answer *= i;
  return answer;
}

// We've implemented this as a recursive function - a function
// that calls a simpler version of itself
int GCD(int n, int m) {
  n = abs(n);
  m = abs(m);
  if ( n == 0 || m == 0 )  // special case, and ensures we don't
    return 1;              // divide by zero below
  else if ( m % n == 0 )
    return n;
  else
    return GCD(m%n, n);
}

bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2) {
  double discriminant = pow(b, 2) - 4 * a * c;
  if ( discriminant < 0 )
    return false;
  root1 = (-1 * b + sqrt(discriminant)) / (2 * a);
  root2 = (-1 * b - sqrt(discriminant)) / (2 * a);
  return true;
}

double Avg(double x, double y) {
  return ((x+y)/2); 
}
double Avg(double x, double y, double z) {
  return (x+y+z)/3; 
}
char Avg(char x, char y) {
  return (x+y) / 2; 
}

double testavg(double t1, double t2, double t3, double t4, double t5) {
  return (t1 + t2 + t3 + t4 + t5) / 5;
}

/* 
terrible recursion tbh use solved recurrence relation to write 
a constant time function */ 
int Fibonacci(int n) {
  if(n < 2) {
    return 1; 
  }
  else {
    return Fibonacci(n-1) + Fibonacci(n-2); 
  }
}