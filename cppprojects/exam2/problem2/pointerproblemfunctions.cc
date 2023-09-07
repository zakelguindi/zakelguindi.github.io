// Copyright 2023 Zak Elguindi
// Merge function implemented by Zak Elguindi
// Print function implemented by bhipp
#include"pointerproblemfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

// do not modify the implementation of the Print function
void Print(const SortedDynamicArray * nums) {
  // cout <<"nums size: " << nums->size << endl;  
  for ( int i = 0; i < nums->size; ++i )
    cout << setw(4) << nums->values[i];
  cout << endl;
}

// implement the Merge function (described in pointerproblemfunctions.h) here
void Merge(SortedDynamicArray * const array1, const SortedDynamicArray * const array2) {
  //fill an array with both 
  //cut down duplicates 
  //need to delete values 
  /**
   * free up space from the previous data (that isn't being used anymore)
   * */
  int originaltotalsize = array1->size + array2->size; 
  SortedDynamicArray * array3 = new SortedDynamicArray[originaltotalsize]; 
  for(int i=0; i<array1->size; i++) {
    array3[i].values = array1[i].values; 
  }
  for(int i=array1->size; i<originaltotalsize; i++) {
    array3->values[i] = array2->values[i-array1->size]; 
  }
  //array 3 is filled 
  //sort
  for(int i=0; i<originaltotalsize; i++) {
    for(int j=0; j<originaltotalsize; j++){ 
      if(array3->values[j] > array3->values[j+1]) {
        int temp = array3->values[j]; 
        array3->values[j] = array3->values[j+1]; 
        array3->values[j+1] = temp; 
      }
    }
  }
  int temp[originaltotalsize]; 
  int j=0; 
  for(int i=0; i<originaltotalsize; i++) {
    if(array3->values[i] != array3->values[i+1]) {
      temp[j++] = array3->values[i]; 
    }
  }
  temp[j++] = array3->values[originaltotalsize]; //works for last value

  for(int i=0; i<j; i++) {
    array3->values[i] = temp[i]; 
  }
  //array has no duplicates 
  delete [] array1->values; //no leaks 
  array1->size = j; //prints all remaining values 

  //now point it to array1 
  for(int i=0; i<j;i++) {
    array1->values[i] = array3->values[i]; 
    // cout << "FINAL TEST AT "<<i << ": " << array1->values[i] << endl; 
  }
}