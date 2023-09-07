//Copyright 2023 Zak Elguindi 
//Define the SalariedEmployee class- child of employee 
#ifndef _SALARIED_EMPLOYEE_H_
#define _SALARIES_EMPLOYEE_H_

#include"employee.h"
#include<string>
using std::string; 
namespace CS240_Employees {

class SalaryEmployee : public Employee { 
 public: 
  //constructor- with all individual data members 
  explicit SalaryEmployee(string f="Jane", string l = "Doe", 
                            string job = "TBD", int payPeriods = 52, 
                            double salary = 0); 
  //constructor- create salaried employee from an existing employee 
  explicit SalaryEmployee(const Employee& employee, double salary = 0); 
  //accessor 
  double GetSalary() const { return annualSalary_; }
  //mutator 
  void SetSalary(double s); 
  //redefine print function 
  void Print() const; 
  //pay function 
  double Pay() const; 
 private: 
  double annualSalary_; 
};

} //end namespace cs240_employees 

#endif // _SALARIED_EMPLOYEE_H_