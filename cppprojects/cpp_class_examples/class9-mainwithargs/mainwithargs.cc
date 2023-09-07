//Copyright 2023 Zak Elguindi 
//example main function w arguments 
#include<iostream>
using std::cin; 
using std::cout; 
using std::endl; 
#include<fstream> //use for program 3 
using std::ifstream; 

int main(int num_cstrings, char * the_cstrings[]) {
  ifstream input_file(the_cstrings[1]); 
  char next; 
  input_file >> next; 
  while(input_file.good())  {//while file isn't empty
  cout << next; 
  input_file >> next;
  }
  cout << endl; 
  input_file.close(); 
}


/*
int main( int num_cstrings, char * the_cstrings []) {
  cout << num_cstrings << endl; 
  for(int i=0; i<num_cstrings; i++) {
    cout << the_cstrings[i] << endl; 
  }
  return 0; 
}*/