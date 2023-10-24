//Copyright 2023 Zak Elguindi
#include<iostream>
#include<string>
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 

int main() {
  /**
   * n lockers numbered 1 to n 
   * r passes by the lockers 
   * on i'th pass, toggle the door of every i locker  
   * if door is closed, open it 
   * you pass by n lockers r times 
   * on your first pass, toggle first locker 
   * second pass, second locker 
   * 
   * 
   * */

  int lockersize, passes; 
  cout << "Enter a number of locker doors" << endl; 
  cin >> lockersize; 
  cout << "Enter a number of passes" << endl; 
  cin >> passes; 

  //convert lockers to array 
  int lockers[lockersize]; 
  for(int i=1; i<=lockersize; i++) {
    lockers[i] = 0; 
  }

  //locker loop inside of pass loop. closed = 0, open = 1 
  for(int i=1; i<=passes; i++) {
    for(int j=1; j<=lockersize; j++) {
      if((j % i) == 0) {
        if(lockers[j] == 0) {
          lockers[j] = 1; //opened
        } else {
          lockers[j] = 0; //closed
        }
      }
    }
  }

  int openCounter = 0; 
  cout << "\nAfter "<<passes<<" passes..." << endl; 
  for(int i =1; i<= lockersize; i++) {
    cout << "Locker #" << i <<": ";  
    if(lockers[i] == 1) {
      cout << "Open"; 
      openCounter++; 
    } else {
      cout << "Closed"; 
    }
    cout << endl; 
  }  
  cout << "There are: " <<openCounter<< " Lockers open" << endl; 

  return 0; 
}