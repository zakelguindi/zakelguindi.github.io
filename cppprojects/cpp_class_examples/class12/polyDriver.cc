//Copyright 2023 Zak Elguindi 
//test drive the functionality of our Polynomial class
#include<iostream> 
using std::cout; 
using std::cin; 
using std::endl; 
#include"polynomial.h"

int main() {

  Polynomial::SetVariable('t'); 
  
  Polynomial p; 
  cout << p << endl; 
  p[3] = 6; 
  p[5] = 2; 
  cout << p << endl;
  
  Polynomial p2; 
  p[3] = 9; 
  p[2] = 7; 
  cout << p2 << endl; 
  cout << p + p2 << endl; //using + operator after it's been overloaded 

  /*
  Polynomial p1, p2(3); 
  /**
   *  +    p1 + p2   ==  operator "+" (p1, p2) if operator is standalone function
   *                    p1.operator + (p2) if the operator is a member of the Polynomial class 
   * 
   * <<   cout << p1    we can't make << a member of the Polynomial class because the left operand is not a Polynomial
  
  
  cout << p1 << "\n" << p2 << endl;
  p1.SetDegree(6); 
  p1 = p2; //if not overloaded explicitly, assignment operator will be created for us to do a memberwide copy- this is BAD if we have pointers as data members, so we'll need to overload this ourselves
  cout << p1 << endl; 
  p1.SetDegree(10); 
  cout << p1 << endl; 
  p1.SetDegree(2); 
  cout << p1 << endl; //memory allocation+reallocation 
  p1.SetDegree(2); 
  cout << p1 << endl; 
  p1.SetDegree(-8); 
  cout << p1 << endl; */ 
}