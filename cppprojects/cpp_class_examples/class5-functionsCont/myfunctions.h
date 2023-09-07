//Copyright 2023 Zak Elguindi 
//my reusable functions 

//          PROJECT_PATH_FILENAME_H_  (per google style guide)
#ifndef _MYFUNCTIONS_H_
#define _MYFUNCTIONS_H_

//for every header file, you have the two above lines (must match) 

#include<iostream> 
using std::cout; 
using std::endl; 
using std::cin; 
#include"myfunctions.h" 

//factorial function prototype 
int Factorial(int); 

//greatest common divisor prototype 
int gcd(int, int);


/*int Factorial(int n) {
  if(n<0) {
    cout << "Factorial is not defined for negative integers" << endl; 
    return 0; 
  }
  int answer = 1; 
  for(int i=2;i<=n;i++) {
    answer *=i; 
  }
  return answer; 
} */ 

#endif // _MYFUNCTIONS_H_