//Copyright 2023 Zak Elguindi

#include<iostream>
using std::cout; 
using std::endl; 
#include"set.h"
using namespace Project3Problem3; 

int main() {
  int values[4] = {11,2,5,0};
  const Set set1(4, values); 
  int values2[4] = {4,8,3,3}; 
  const Set set2(4, values2); 

  set1.Intersection(set2).Print(); 
  set1.Print(); 
  bool test2 = set2 == set1;  
  if(test2) {
    cout << "congrats" <<endl; 
  } else { 
    cout <<"tough" << endl; 
  }
}