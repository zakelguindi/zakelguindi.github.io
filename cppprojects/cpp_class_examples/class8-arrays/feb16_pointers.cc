//Copyright 2023 Zak Elguindi 
//intro to pointers c++ 
#include<iostream> 
using std::cout; 
using std::cin; 
using std::endl; 

//void Double(int & x ) {
void Double( int * x ) {
  *x *= 2;  //instead of x *= 2; 
}

//two function names- work exactly the same: 
//void DoubleIt(int an_array[], int size) {
void DoubleIt(int * const an_array, int size) {
  for(int i=0; i<size; i++) {
    an_array[i] *= 2; 
  }
}

int main() {
  int anumber = 15; 
  Double(&anumber); 
  cout << "after the call number " << anumber << endl; 
  const int kSize = 10; 
  int some_nums[kSize] = {-2, 15, 7, 28, 4}; 
  DoubleIt(some_nums, kSize); 
  for(int i=0; i<kSize; i++) {
    cout << some_nums[i] << " "; 
  }
  cout << endl; 
  return 0; 
}

/*
int main() {
  double * dptr; //dptr is a pointer to a double 
  double num = 3.76; 
  cout << "&num = " << &num << endl; 
  cout << "num = " <<num << endl;
  cout << "&dptr = " <<&dptr << endl; 
  cout << "dptr = " <<dptr << endl;
  cout << "*dptr = " << *dptr << endl; 
  cout << "dptr[0] = " << dptr[0] << endl; 
  ++dptr; 
  cout << "dptr = " << dptr << endl; 
  cout << "*dptr = " << *dptr << endl; 
  return 0; 
}
*/