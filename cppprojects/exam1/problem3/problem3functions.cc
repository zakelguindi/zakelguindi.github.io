//Copyright 2023 Zak Elguindi

#include"problem3functions.h"
#include<iostream> 
#include<cmath> 
using std::cout; 
using std::cin; 
using std::endl; 

int NumDigits(int num) {
  int digits = 1; 
  while(num / 10 != 0) {
    num = num / 10; 
    digits++; 
  }
  return digits; 
}

bool FindAndReplace(int& x, int find, int replace)
{
  if(find < 0 || replace < 0 || NumDigits(find) < NumDigits(replace)) {
    return false; 
  }
  /**
   * find digits in x
   * for every digit in x, if 10^digit = find, find = replace 
   * */
  //need ogx and abs(x) for negative numbers- can't switch them if negative
  int ogx = x; 
  x = abs(x); 
  int tempx = 0; 
  int digits = NumDigits(x);
  int findDigits = NumDigits(find); 

  for(int i=0; i<digits; i++) {
    int multiplier = pow(10, i); 
    int modValue = pow(10, findDigits); 
    int digit = (x / multiplier) % modValue; 

    if(digit == find) { 
      if(findDigits > 1) {
        i = i + findDigits - 1; 
      }
      tempx += multiplier * replace;  
    }
    else {
      digit = (x / multiplier) % 10; 
      tempx += multiplier * digit; 
    }
  }
  //switching sign back if negative originally 
  if(ogx < 0) {
    tempx = tempx * (-1); 
  }
  x = tempx; 
  return true; 
}