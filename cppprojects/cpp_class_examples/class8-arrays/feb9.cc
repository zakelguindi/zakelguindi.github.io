//Copyright 2023 Zak Elguindi 
//array day 

#include<iostream> 
#include<iomanip>
using std::cout; 
using std::cin; 
using std::endl; 


void PrintArray(double array[], int size) {
  cout << std::setiosflags( std::ios::fixed | std::ios::showpoint ); 
  for ( int i=0; i< size; i++) {
    cout << std::setw(10) << array[i] << " ,";
  }
  cout << endl; 
}

//Linear Search 
int LinearSearch(const double array[], int size, double searchVal) {
  int foundPos = -1; //-1 means it hasn't been found
  int i =0; 
  while(foundPos == -1 && i < size) {
    foundPos = (array[i] == searchVal ? i : -1); 
    i++;
  }
  return foundPos; 
}

int main() {
  const int kSize = 8; //how to write constant per GSG 
  /*
  we'll declare and initialize constant variables for our array sizes 
  allows for easier code maintenance (update size in one spot) 
  */ 
  double someNums[kSize] = {2.4, 5.1, 0.053}; 
  PrintArray(someNums, kSize); 

  const double some_consts[] = {3.14, 1.45, 2.718}; 

  //c-string 
  char word[] = "Hello"; // {'H', 'e', 'l', 'l', 'o', '\0'}; 

  /*
  for(int j=0; j<kSize; j++) {
    cin >> someNums[j]; 
  }
  for(int i=0; i<kSize;i++) {
    cout << someNums[i] << ", ";
  }
  cout << endl; 
  */
  return 0; 
}