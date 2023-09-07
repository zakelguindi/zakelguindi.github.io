// Copyright 2023 bhipp
// test the GCD function in myfunctions.h
#include<iostream>
using std::cout;
using std::endl;
#include"myfunctions.h"

int main() {
  int x = -15, y = -45;
  if ( GCD(x, y) == 15  && x == -15 && y == -45 )
    cout << "Passed GCD(x, y ) test " << endl;
  else
    cout << "Failed GCD(x, y) test " << endl;

  if ( GCD(9, 15) == 3 )
    cout << "Passed GCD(9, 15) test " << endl;
  else
    cout << "Failed GCD(9, 15) test " << endl;

  if ( GCD(1113, 1111) == 1 )
    cout << "Passed GCD(1111, 1111) test " << endl;
  else
    cout << "Failed GCD(1113,1111) test" << endl;

  if ( GCD(-18, 180) == 18 )
    cout << "Passed GCD(-18,180) test " << endl;
  else
    cout << "Failed GCD(-18,180) test " << endl;

  if ( GCD(5, 0) == 1 )
    cout << "Passed GCD with 0 test" << endl;
  else
    cout << "Failed GCD with 0 test" << endl;

  return 0;
}
