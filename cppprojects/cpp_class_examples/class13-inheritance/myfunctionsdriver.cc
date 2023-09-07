//Copyright 2023 Zak Elguindi 
//test the functions in my_functions
#include"my_functions.h"
//using cs240_functions::some_function; 
using namespace cs240_functions; //for entire namespace 

int main() {
  cs240_functions::some_function(); //must call the namespace (don't need line 4)
  some_function(); //works if you have "using cs240_functions::some_function" at the top (line 4)
  return 0; 
}