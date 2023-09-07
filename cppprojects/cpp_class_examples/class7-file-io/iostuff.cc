//Copyright 2023 Zak Elguindi 
//Examples of file i/o
#include<fstream> // for ifstream and ofstream 
using std::ofstream;  //ofstream - output file stream 
using std::ifstream; 


int main() {
  int num; 
  ifstream my_input_file("someinput.txt"); 
  ofstream my_output_file("someoutput.txt", std::ios::app); //std::ios::app appends to file, it will overwrite without it
  my_input_file >> num; 
  //will write to a txt file 
  while(my_input_file.good()) {
    my_output_file << num << ", "; 
    my_input_file >> num; 
  }
  my_output_file << "Hello World"; 

  return 0; 
}