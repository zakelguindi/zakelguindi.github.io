//Copyright 2023 Zak Elguindi   
//functions 
#include<iostream> 
using std::cout; 
using std::cin; 
using std::endl; 
#include<cstdlib> // rand(), srand 
#include<ctime> //time- gives current time from the system 
#include<cmath> //has multiple math functions- double pow( double base, double exponent )
                //sqrt(double); ceil(double); floor(double) 


//prototype for a function that rounds to nearest integer 
int roundit( double); 

//iimplementing prototype "roundit" 
int roundit(double num) { 
  return floor(num + 0.5); 
}


int main () {
  char name[] = ""; 
  cout << "What is your name "; 
  cin >> name; 
  cout << "\nYour name is: " << name; 
  cout << "\nName length is: " << sizeof(name); 

  for(int i=0; i<sizeof(name); i++) {
    if(name[i] == ' ') {
      cout << "\ntest complete"; 
    }
  }

  cout << "int = " << sizeof(int) << "\nlong = " << sizeof(long) 
    << "\nshort = " <<sizeof(short) << endl; 

  cout << pow( 8, 0.5); 
  double num; 

  cout << "\nEnter a decimal number"; 
  cin >> num; 
  cout << "rounded with out function " << roundit(num); 
  cout << "\nsquare root = " << sqrt(num) << "\nceiling = " << ceil(num) 
      << "\nfloor = " << floor(num) << endl; 

  srand(time(0)); 
  for(int i=0; i<10; i++) {
    cout << rand() % 6 + 1 << endl; //gives number between 1 and 6
  }
  return 0; 
}