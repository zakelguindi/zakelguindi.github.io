//Copyright 2023 Zak Elguindi
//Implement Employee Class functionality 
#include"employee.h"
#include<iostream>
using std::cout; 
using std::endl; 
#include<string>
using std::string; 

namespace CS240_Employees {

Employee::Employee(string f, string l, string job, int payPeriods) :
firstName_("Jane"), lastName_("Doe"), jobTitle_("TBD"), payPeriods_(52) {
  SetFirst(f); 
  SetLast(l); 
  SetJobTitle(job); 
  SetPayPeriods(payPeriods); 
}

Employee::~Employee() {
  cout << "I'm sorry, " << firstName_ << "but we're going to have to let you go." << endl; 
}

void Employee::SetFirst(string f) {
  if(f.length() > 0) 
    firstName_ = f; 
}
void Employee::SetLast(string l) {
  if(l.length() > 0) 
    lastName_ = l; 
}

void Employee::SetJobTitle(string job) {
  if(job.length() > 0) 
    jobTitle_ = job; 
}
void Employee::SetPayPeriods(int ppy) {
  if( ppy == 12 || ppy == 24 || ppy == 26 || ppy == 52 || ppy ==365) 
    payPeriods_ = ppy; 
}
void Employee::Print() const {
  cout << "Employee Name: " <<firstName_ << " " << lastName_ 
        << "\nJob Title: " << jobTitle_ 
        << "\nPay Periods Per Year: " << payPeriods_ << endl; 
}


} //end namespace CS240_Employees 
