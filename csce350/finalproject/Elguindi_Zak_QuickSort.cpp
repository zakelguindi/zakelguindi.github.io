#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using std::max; 
using std::min; 
using std::queue; 
using std::cin; 
using std::cout; 
using std::endl; 


void Swap(int& a, int& b) {
  int temp = a; 
  a = b; 
  b = temp; 
};


int MedianOf(int a, int b, int c) {
  // check a then b then c 
  //if a > b and a < c OR a > c and a < b, then a is median 
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

int HoarePartition(int* numbers, int left, int right) {
  //no bugs in Hoare
  int pivot = numbers[left];
  int middle = floor((left + right)/2); 
  // int pivot = numbers[MedianOf(numbers[left], numbers[middle], numbers[right])];

  int i = left; 
  int j = right; 

  int split = 0;
  for(int k = left+1; k <= right; k++) {
    if(numbers[k] <= pivot) {
      split++;
    }
  }

  int splitIndex = split + left; 

  Swap(numbers[splitIndex], numbers[left]); 
  
  while(i < splitIndex && j > splitIndex) {
    while(numbers[i] <= pivot) {
      i++; 
    }
    while(numbers[j] > pivot) {
      j--;
    }
    if(i < splitIndex && j > splitIndex) {
      Swap(numbers[i++], numbers[j--]);
    }
  }

  return splitIndex; 
};



void QuickSort(int* numbers, int left, int right) { 

  // cout << "ORIGINAL: "; 
  // for(int i=0; i<right; i++) {
  //   cout << numbers[i] << ", "; 
  // }
  // cout << endl; 

  if(left >= right) {
    return; 
  }

  int split = HoarePartition(numbers, left, right); 

  QuickSort(numbers, left, split-1); 
  QuickSort(numbers, split+1, right); 
  
};




int main() {
  int numbers[] = {5, 3, 1, 9, 8, 2, 4, 7};
  int size = *(&numbers + 1) - numbers; 
  cout << "SIZE: " << size << endl; 

  queue<int> nums; 

  QuickSort(numbers, 0, size); 
  // int size = *(&numbers + 1) - numbers; 
  for(int i=0; i<size; i++) {
    cout << numbers[i] << ", "; 
  }
  cout << endl; 
}