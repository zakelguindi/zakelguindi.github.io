#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<string>
#include<chrono>
using namespace std::chrono; 
using std::string; 
using namespace std; 
using std::max; 
using std::min; 
using std::cin; 
using std::cout; 
using std::endl; 

/**
 * create makefile for quicksort only 
 * generate the random inputs 
 * quicksort inputs and add them to the list 
 * print execution times to output.txt 
 * 
 * */


//tested and works
void Swap(int * nums, int a, int b) {
  if(a == b) {
    return; 
  }
  int temp = nums[a]; 
  nums[a] = nums[b]; 
  nums[b] = temp; 


};


//tested and works 
int MedianOf(int a, int b, int c) {
  // check a then b then c 
  //if a > b and a < c OR a > c and a < b, then a is median 
  if(a == b || a == c) {
    return a; 
  } else if( b == c) {
    return b; 
  }
  if((a > b && a < c) || (a > c && b > c)) {
    return a; 
  }
  //if b > a and b < c OR b > c and b < a 
  else if((b > a && b < c)|| (b > c && b < a)) {
    //median is b
    return b; 
  } else {
    //if it's not a or b, it's c 
    return c; 
  }
}



void HoarePartition(int* numbers, int left, int right, int pivot, int& piv1, int& piv2) {
  piv1 = 0; 
  piv2 = 0; 

  int l = left; 
  int r = left; 
  int u = right; 

  while( r <= u) {
    if(numbers[r] < pivot) {
      Swap(numbers, l, r); 
      l++; 
      r++; 
    } else if(numbers[r] > pivot) {
      Swap(numbers, r, u); 
      u--; 
    } else {
      //numbers are even 
      r++; 
    }
  }
  piv1 = l; 
  piv2 = r; 
};

//can handle duplicates now
void Sort(int* numbers, int left, int right) {
  
  if(left < right) {

    int pivot = numbers[left]; 
    if((left-right) > 3) {
      int middle = floor((left+right)/2); 
      int pivotIndex = MedianOf(numbers[left], numbers[middle], numbers[right]); 
      pivot = numbers[pivotIndex]; 
    }


    int leftPiv = 0;
    int rightPiv = 0; 
    HoarePartition(numbers, left, right, pivot, leftPiv, rightPiv); 

    Sort(numbers, left, leftPiv-1); 
    Sort(numbers, rightPiv, right); 

  }
};
