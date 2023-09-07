//Copyright 2023 Zak Elguindi
//test Employee Classes 
#include"employee.h"
using CS240_Employees::Employee; 
#include<fstream>
using std::ifstream; 
#include"hourlyemployee.h"
using CS240_Employees::HourlyEmployee; 

int main() {
  HourlyEmployee e1, e2("Joe", "Shmoe", "programmer", 12); 
  e1.Print();
  e2.Print(); 
  e1.SetJobTitle("manager"); 
  e1.SetLast(""); 
  e1.Print(); 
}