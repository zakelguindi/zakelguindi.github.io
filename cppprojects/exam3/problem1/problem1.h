// Copyright 2023 Zak Elguindi
// Problem header file

#ifndef _PROBLEM1_H_
#define _PROBLEM1_H_
#include<iostream>
using std::cout;
using std::endl;

namespace Project3Problem1 {

template<class TheType>
TheType Median(const TheType array1[], const int size) {
  TheType array2[size];
  for ( int i = 0; i < size; i++ ) {
    array2[i] = array1[i];
  }
  cout << endl;

  for (int i = 1; i < size; i++) {
    // see if this can be changed to show it in reverse,
    // otherwise nbd (check old projects)
    while (array2[i] > array2[i-1] && i > 0) {
      TheType temp = array2[i];
      array2[i] = array2[i-1];
      array2[i-1] = temp;
      i--;
    }
  }
  // array is now sorted
  int medianIndex = size/2;
  TheType median = 0;
  if (size % 2 == 0) {
    // number, two medians
    median = (array2[medianIndex] + array2[medianIndex - 1]) / 2;
  } else {
    // odd
    median = array2[medianIndex];
  }
  return median;
}

}  // end namespace Project3Problem1

#endif  // _PROBLEM1_H_
