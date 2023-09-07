//Copyright 2023 Zak Elguindi 
//more arrays c++

#include<iostream>
using std::cout; 
using std::cin;
using std::endl; 
#include<cstdlib> //rand and srand 
#include<ctime> //for time 
#include<iomanip> //for setw 

//function to print values in an integer array
void Print(const int nums[], int size);
//function to fill an integer with "random" values
void Populate(int nums[], int size); 

//insertion sort- n^2 (has great base case of N)
void InsertionSort(int nums[], int size); 

//binary search- only works on sorted arrays
int BinarySearch(const int nums[], int lookin4, int top, int bottom=0); 

int main() {
  srand(time(0)); //seed the random function with the current time so a diff list of values are generated 
  const int kSize = 15; 
  int some_numbers[kSize] = {3, 16, 9}; 
  Print(some_numbers, kSize); 
  Populate(some_numbers, kSize); 
  Print(some_numbers, kSize); 
  InsertionSort(some_numbers, kSize); 
  Print(some_numbers, kSize); 
  int search_value; 
  cout << "What are you searching for?"; 
  cin >> search_value; 
  cout << "hello"; 
  cout << BinarySearch(some_numbers, search_value, kSize-1) << endl; 
  return 0; 
}

int BinarySearch(const int nums[], int lookin4, int top, int bottom) {
  int middle = (bottom + top) /2; 
  if(nums[middle] == lookin4) {
    return middle; 
  }
  else if( bottom >= top) {
    return -1;
  }
  else if( nums[middle] > lookin4 ) {
    return BinarySearch(nums, lookin4, middle-1, bottom); 
  }
  return BinarySearch(nums, lookin4, top, middle+1); 
}

void InsertionSort(int nums[], int size) {
  for( int place = 1; place < size; place++) {
    while(nums[place] < nums[place-1] && place > 0) {
      int temp = nums[place]; 
      nums[place] = nums[place-1]; 
      nums[place-1] = temp; 
      place--; 
    }
  }
}

void Print(const int nums[], int size) {
  for(int i=0; i<size; i++) {
    cout << std::setw(5) << nums[i]; 
  }
  cout << endl; 
}

void Populate(int nums[], int size) {
  for(int i=0; i<size; i++) {
    nums[i] = rand() %  100; 
  }
}