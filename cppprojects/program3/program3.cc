//Copyright 2023 Zak Elguindi 

#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 
#include<fstream> 
using std::ifstream; 
#include"program3functions.h"

int main(int argc, char * argv[]) {
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, 
      I = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, 
      q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, 
      y = 0, z = 0; 
  const int size = 26; 
  int counter[size] = {a, b, c, d, e, f, g, h, I, j, k, l, 
    m, n, o, p, q, r, s, t, u, v, w, x, y, z};
  
  char alphabet[size] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  ifstream input_file(argv[1]);
  char next; 
  input_file >> next; 
  while(input_file.good()) {
    Check(next, counter, size); 
    input_file >>next; 
  }
  input_file.close(); 

  char originalAlphabet[size]; 
  for(int i=0; i<size; i++) {
    originalAlphabet[i] = alphabet[i]; 
  }

  int originalCounter[size];
  for(int i=0; i<size; i++) {
    originalCounter[i] = counter[i]; 
  }

  Sort(counter, alphabet, size); 
  SearchHighest(counter, alphabet, size); 
  SearchLowest(counter, alphabet, size); 
  cout << endl; 
  Print(counter, alphabet, size); 
  cout << endl; 
  Chart(counter, originalCounter, originalAlphabet, size); 
}