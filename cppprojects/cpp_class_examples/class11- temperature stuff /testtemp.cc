//Copyright 2023 Zak Elguindi 
//Test drive the functionality of the Temperature class 
#include"temperature.h"
#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

int main() {
  //when calling the def constructor, DON'T place empty parenthesis after the variable name
  Temperature t;
  t.SetValue(70); 
  t.SetUnit("Fahrenheit"); 
  cout << t.GetValue() << " " << t.GetUnits() << endl; 
  Temperature t2(50), t3(75, "Fahrenheit"); 
  cout << t2.GetValue() << " " << t2.GetUnits() << endl; 
  t3 = t; //default assignment operator will do a memberwise copy of data members. Will cause issues for pointers as data members 

  cout << t3.GetValue() << " " << t3.GetUnits() << endl; 
  return 0; 
}