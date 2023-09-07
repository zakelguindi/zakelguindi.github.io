//Copyright 2023 Zak Elguindi 
//implement functionality of salaried_employee.h
#include<string>
using std::string; 
#include"salaried_employee.h"
#include"employee.h"
#include<iostream>
using std::cout; 
using std::endl; 

namespace CS240_Employees { 

SalaryEmployee::SalaryEmployee(string f, string l, 
                                  string job, int payPeriods, double salary) : 
                                  Employee(f, l, job, payPeriods), annualSalary_(0) { 
  SetSalary(salary); 
}

SalaryEmployee::SalaryEmployee(const Employee& emp, double salary) 
                                  : Employee(emp), annualSalary_(0) { 
  SetSalary(salary); 
}

void SalaryEmployee::SetSalary(double salary) { 
  if( salary > 0) 
    annualSalary_ = salary; 
}

double SalaryEmployee::Pay() const {
  return annualSalary_ / GetPayPeriods(); //payPeriods_; 
}

} // end namespace CS240_Employees