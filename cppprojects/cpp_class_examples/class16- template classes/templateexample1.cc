// Copyright 2023 bhipp
// first template examples
#include<iostream>
using std::cout;
using std::endl;

template<class T>
T Average(T x, T y) { return ( x + y ) / 2; }

// int Average(int x, int y) { return (x + y) / 2; }
// char Average(char x, char y) { return (x + y) / 2; }
// double Average(double x, double y) { return (x + y) / 2; }

int main() {
  int num1 = 4, num2 = 7;
  cout << Average(num1, num2) << endl;
  char letter1 = 'a', letter2 = 'z';
  cout << Average(letter1, letter2) << endl;
  double d1 = 4, d2 = 7;
  cout << Average(d1, d2) << endl;

  return 0;
}
