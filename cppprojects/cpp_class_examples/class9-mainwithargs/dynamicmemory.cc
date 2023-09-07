//Copyright 2023 Zak Elguindi 
//pointers and dynamic memory location 
#include<iostream>
using std::cin; 
using std::cout; 
using std::endl; 

int main() {
  int size; 
  double * some_numbers; 
  do {
    cout << "How many do you need ?"; 
    cin >> size; 
  } while (size <= 0); 
  some_numbers = new double[size]; //new will return the address of the dynamic allocated memory 
  if(some_numbers == nullptr) {
    cout << "Couldn't reserve the requested memory" << endl; 
    return 0; 
  }
  cout << "Enter your " << size << " numbers: "; 
  for ( int i=0; i<size; i++ ) {
    cin >> some_numbers[i]; 
  }
  cout << "Here they are: "; 
  for(int i=0; i< size; i++) {
    cout << some_numbers[i] << " "; 
  }
  cout << endl; 

  //whenever we're finished with the dynamically allocated memory
  /**
   * frees up block of memory that some_numbers points to
   * done so it can be used for other purposes
   * */
  delete [] some_numbers; 
  /**
   * some_numbers is still around,we will either set
   * it to a new mem location or set it to the nullptr
   * to ensure we know it's not pointing anywhere 
   * */
  some_numbers = nullptr; 
  return 0; 
}