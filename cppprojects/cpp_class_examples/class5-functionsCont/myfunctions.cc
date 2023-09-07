//Copyright 2023 Zak Elguindi 

#include"myfunctions.h"
#include<iostream>
using std::cout; 
using std::endl; 

int Factorial(int n) {
  if(n<0) {
    cout << "Factorial is not defined for negative integers" << endl; 
    return 0; 
  }
  int answer = 1; 
  for(int i=2;i<=n;i++) {
    answer *=i; 
  }
  return answer; 
}

//recursion gcd solution 
int gcd(int n, int m) {
  if( m % n == 0) {
    return n;
  }
  else {
    return gcd(m%n, n); 
  }
}