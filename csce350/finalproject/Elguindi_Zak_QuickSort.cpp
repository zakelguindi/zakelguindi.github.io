#include<iostream>
#include<algorithm>
#include<cmath>
using std::max; 
using std::min; 
using std::cin; 
using std::cout; 
using std::endl; 


//tested and works
void Swap(int * nums, int a, int b) {
  if(a == b) {
    // cout << "EQUAL NUMBERS" << endl;
    return; 
  }
  int temp = nums[a]; 
  nums[a] = nums[b]; 
  nums[b] = temp; 


};


//tested and works 
int MedianOf(int a, int b, int c) {
  cout << "Finding... " <<a << ", " << b << ", and " << c << endl; 
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

int HoarePartition(int* numbers, int left, int right) {


  int pivot = numbers[left]; 
  if((left-right) > 3) {
    int middle = floor((left+right)/2); 
    int pivotIndex = MedianOf(numbers[left], numbers[middle], numbers[right]); 
    pivot = numbers[pivotIndex]; 
  }

  int i = left--; 
  int j = right++; 

  while(i < j) {
    while(numbers[i] < pivot) {
      i++; 
    }
    while(numbers[j] > pivot) {
      j--;
    }
    if(i >= j) {
      return j; 
    }

    Swap(numbers, i, j); 
  }
  return j; 
};



void QuickSort(int* numbers, int left, int right) { 
  
  if(left < right) {

    int split = HoarePartition(numbers, left, right); 

    QuickSort(numbers, left, split); 
    QuickSort(numbers, split+1, right); 
  }
};




int main() {
  int numbers[] = {5, 3, 1, 11, 8, 2, 4, 7};
  int size = sizeof(numbers)/sizeof(numbers[0]);

  cout << "PRE SORT: "; 
  for(int i=0; i<size; i++) {
    cout << numbers[i] << ", "; 
  }
  cout << endl; 

  QuickSort(numbers, 0, size - 1);   

  cout << "POST SORT: "; 
  for(int i=0; i<size; i++) {
    cout << numbers[i] << ", "; 
  }
  cout << endl; 


  return 0; 
}