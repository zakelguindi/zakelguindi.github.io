

#include<iostream>
#include<string>
#include<cmath>
using std::cout; 
using std::endl; 
using std::string; 

int main() {
  //find distance between two numbers in an array 

  int array[7] = {3, 7, 0, 8, 6, 1, 8};

  cout << "Hello" << endl; 
  int dmin = 100; 

  for(int i=0; i<7; i++) {
    for(int j=i; j<7; j++) {
      if(i != j && sqrt((array[i]-array[j])*(array[i]-array[j])) < dmin) {
        dmin = sqrt((array[i]-array[j])*(array[i]-array[j]));
        cout << "num 1: " << array[j] << ", num 2: " << array[i] << endl; 
        if(dmin < 1) {
          cout << "min dmin reached: " << dmin << endl; 
          return dmin;
        } 
      }
    }
  }

  cout << "Dmin: " << dmin << endl; 
  return dmin; 


}