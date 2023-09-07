// Copyright 2023 bhipp
// test functions from mytemplatefunctions.h
#include<iostream>
using std::cout;
using std::endl;
#include<ctime>
#include<cstdlib>
#include"mytemplatefunctions.h"
using namespace csce240_template_functions;

int main() {
  int i1 = 7, i2 = 4;
  cout << "i1 = " << i1 << " and i2 = " << i2 << endl;
  SwapValues(i1, i2);
  cout << "i1 = " << i1 << " and i2 = " << i2 << endl;

  const int kSize = 15;
  srand(time(0));
  int nums[kSize];
  for ( int i = 0; i < kSize; ++i )
    nums[i] = rand() % 10;
  for ( int i = 0; i < kSize; ++i )
    cout << nums[i] << " ";
  cout << endl;
  QuickSort(nums, 0, kSize - 1);
  for ( int i = 0; i < kSize; ++i )
    cout << nums[i] << " ";
  cout << endl;
  return 0;
}

