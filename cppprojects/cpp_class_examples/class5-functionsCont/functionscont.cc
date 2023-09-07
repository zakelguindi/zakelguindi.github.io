//Copyright 2023 Zak Elguindi 
//Functions - Separate Compilation 
#include<iostream>
#include<iomanip> 
using std::cout; 
using std::endl; 
using std::cin; 
#include "myfunctions.h"

// factorial function - prototype
int Factorial(int); 

// int main() {
//   int num, num2; 
//   cout << "Enter a non-negative integer "; 
//   cin >> num; 
//   cout << num << "! = " << Factorial(num) << endl; 
//   cout << "Enter another integer ";
//   cin >> num2;
//   cout << "The GCD of " << num << " and " << num2 << " is " << gcd(num, num2) << endl; 
//   return 0; 
// }

/*int Factorial(int n) {
  if(n < 0 ) {
      cout << "Factorial is not defined for negative integers" << endl; 
      return 0; 
  }
  int answer = 1; 
  for(int i=1; i<n;i++) {
    answer *= i;
  }
  return answer; 
} */


//first example
int main() {
  double x, y, z; 
  cout << "Enter a real number"; 
  cin >> x >> y >> z; 
  cout << x << endl; 
  cout << std::setprecision(3) << x << endl; 
  cout << std::setiosflags( std::ios::showpoint | std::ios::fixed);
  cout << std::setw(10) << x << "\n" << std::setw(10) << y << "\n" << 
    std::setw(10) << z << endl; 
  return 0; 
} 