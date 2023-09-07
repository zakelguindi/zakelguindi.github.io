// Copyright 2023 Zak Elguindi 
//test rectangle 
#include<iostream>
using std::cout; 
using std::endl; 
#include"rectangle.h"
#include"square.h"
using cs240_shapes::Square; 
#include<iomanip>
using std::setw; 

void PrintSquare(const Square& s) {
  for(int i=0; i<s.GetLength(); i++) 
    cout << "*"; 
  cout << endl; 
  for(int i=2; i<s.GetLength(); i++) {
    cout << "*" << setw(s.GetLength() -1) << "*" << endl; 
  }
}
int main() {
  //cs240_shapes ::Rectangle r
  cs240_shapes::Square r;
  cout << r << endl; 
  r.SetLength(8); 
  cout << r << endl; 
  PrintSquare(r); 
}