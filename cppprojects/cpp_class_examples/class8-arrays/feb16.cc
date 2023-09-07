//Copyright 2023 Zak Elguindi 
#include<iostream>
using std::cin;
using std::cout; 
using std::endl; 

const int kCols = 5; //this variable has file scope

//function to print the values in a double-subscripted array of doubles 
void Print(double the_array[][kCols], int num_rows) {
  for(int i=0; i<num_rows; i++) {
    for(int j=0; j<kCols; j++) {
      cout << the_array[i][j] << " "; 
    }
    cout << endl; 
  }
}

int main() {
  const int kRows = 6; 
  const int kCols = 5; 
  double nums[kRows][kCols] = { {1.2, 3.7}, {5}, {-4.2}};
  cout << nums[2][1] << endl; 
  Print(nums, kRows); 
}