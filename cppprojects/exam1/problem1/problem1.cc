//Copyright 2023 Zak Elguindi

#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

int main() {

  int letters = 0; 
  int numbers = 0; 
  bool end_char = false; 
  while(!end_char) {
    char c; 
    cin >> c; 
    if(c == '!' || c == '.' || c == '?') {
      end_char = true; 
    }
    else if(isdigit(c)) {
      numbers++; 
    }
    else if (isalpha(c)) {
      letters++; 
    } 
    else {
      
    }
  }
  if(letters == 1 && numbers == 1) {
    cout << "Input sentence contains " << letters << " alphabetic character and " << numbers << " digit." << endl; 
  }
  else if(letters == 1) {
    cout << "Input sentence contains " << letters << " alphabetic character and " << numbers << " digits." << endl; 
  }
  else if(numbers == 1) {
    cout << "Input sentence contains " << letters << " alphabetic characters and " << numbers << " digit." << endl; 
  }
  else {
    cout << "Input sentence contains " << letters << " alphabetic characters and " << numbers << " digits." << endl; 
  }
}