// Copyright 2023 bhipp
// test the Quadratic Formula function in myfunctions.h
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"myfunctions.h"

int main() {
  double a, b, c, r1 = -1, r2 = -1;
  cout << "Enter the coefficient of x^2, the coefficient of x"
      <<  ", and the constant coefficient ";
  cin >> a >> b >> c;
  if ( QuadraticFormula(a, b, c, r1, r2) )
    cout << "Your quadratic has real roots" << endl;
  else
    cout << "Your quadratic doesn't have real roots" << endl;
  cout << "r1 = " << r1 << "\nr2 = " << r2 << endl;
  return 0;
}
