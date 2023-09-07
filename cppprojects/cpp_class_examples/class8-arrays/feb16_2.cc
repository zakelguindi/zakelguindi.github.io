//Copyright 2023 Zak Elguindi 
//double-subscripted character array vs. array of pointers to characters 
#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

int main() {
  const int kWords = 5;
  const int kLength = 10;
  const char words[kWords][kLength] = {"Hi", "Hello", "What's up", "Not Much", "Cheers"}; 
  for(int i=0; i<kWords; i++) {
    cout << words[i] << endl; 
  }
  return 0; 
}