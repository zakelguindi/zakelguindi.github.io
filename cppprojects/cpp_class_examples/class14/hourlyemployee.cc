//Copyright 2023 Zak Elguindi 
//Define The HourlyEmployee class 
#include"hourlyemployee.h"
#include<iostream>
using std::cout; 
using std::endl; 
#include<string>
using std::string; 
#include"employee.h"

namespace CS240_Employees {

HourlyEmployee::HourlyEmployee(string f, string l, string job, int payPeriods, 
                                double payRate, double worked) : Employee(f,l,job,payPeriods), 
                                                                hourlyRate_(7.25), 
                                                                hoursWorked_(40) {
  SetHourlyRate(payRate); 
  SetHoursWorked(worked);                               
}

HourlyEmployee::HourlyEmployee(const Employee& emp, double payRate, double worked) :
                                Employee(emp), hourlyRate_(7.25), hoursWorked_(40) {
  SetHourlyRate(payRate); 
  SetHoursWorked(worked); 
}

void HourlyEmployee::SetHourlyRate(double payRate) {
  if(payRate >= 7.25) 
    hourlyRate_ = payRate; 
}
void HourlyEmployee::SetHoursWorked(double hours) {
  if(hours > 0 && hours <= 24 * 365 / GetPayPeriods()) {
    hoursWorked_ = hours; 
  }
}

void HourlyEmployee::Print() const {
  Employee::Print(); //to call base class version of a redefined function- baseclass::functioncall 
  cout << "Hourly Rate: $" << hourlyRate_; 
  cout << "\nHours Worked: " <<hoursWorked_ << endl; 
}  

//not dealing with overtime at the moment
double HourlyEmployee::Pay() const {
  return hourlyRate_ * hoursWorked_; 
}



} //end CS240 Employees