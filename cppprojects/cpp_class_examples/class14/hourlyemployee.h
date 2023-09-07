//Copyright 2023 Zak Elguindi 
//Define The HourlyEmployee class 
#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_

#include"employee.h" //child of employee class

namespace CS240_Employees {

class HourlyEmployee : public Employee { //public inheritance 
  //automatically takes in all of the employee stuff 
 public: 
  explicit HourlyEmployee(string f="Jane", string l="Doe", string job = "TBD", int payPeriods=52,
                            double payRate = 7.25, double worked = 40); 
  //constructor takes a base class object and add on necessary values to create derived-class object
  explicit HourlyEmployee(const Employee&, double payRate = 7.25, double worked = 40); 

  void SetHourlyRate(double payRate); 
  void SetHoursWorked(double hours); 
  double GetHourlyRate() const { return hourlyRate_; }
  double GetHoursWorked() const { return hoursWorked_; }
  virtual double Pay() const; 

//redefine - functions with the same prototype as function in the base class
//if a function is virtual in base class, it will automatically be virtual in derived class, but it's good to add "virtual" for clarity 
  void Print() const; 

 private: 
  double hourlyRate_; 
  double hoursWorked_; 

}; //end HourlyEmployee class- child of Employee

} //end CS240_Employees

#endif //HOURLY_EMPLOYEE_H_