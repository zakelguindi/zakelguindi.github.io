//Copyright 2023 Zak Elguindi 
//test mean functions in myfunctions.cc

#include<iostream> 
using std::cout; 
using std::cin; 
using std::endl; 
#include"myfunctions.h" 
#include<ctime> 

int main() {
  cout << "Avg(1.5, 2.7) = " << Avg(1.5, 2.7) << endl; 
  cout << "Avg(1.5, 2.7, 10.1 = " << Avg(1.5, 2.7, 10.1) << endl; 
  cout << "Avg('a' , 'c') = " << Avg('a', 'c') << endl; 


  int n; 
  cin >> n; 
  int start = clock(); 
  cout << Fibonacci(n) << endl; 
  cout << clock() - start << endl;

  return 0; 
}