//Copyright 2023 Zak Elguindi 
//DEFINE an employee 
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_ 

#include<string>
using std::string; 

namespace CS240_Employees {

class Employee {
 public: 
  explicit Employee(string f="Jane", string l="Doe", string job="TBD",
                    int payPeriods=52);
  ~Employee(); //aka Fire function 
  void SetFirst(string f); 
  void SetLast(string l); 
  void SetJobTitle(string job); 
  void SetPayPeriods(int ppy); 

  string GetFirst() const { return firstName_; }
  string GetLast() const { return lastName_; }
  string GetJobTitle() const { return jobTitle_; }
  int GetPayPeriods() const { return payPeriods_; }

//virtual functions must be implemented or made "opure virtual" by putting =0
//on the end of the function prototype. if we make the function pure virtual, our class becomes an abstract class and we can't instantiate objects of that class type
  virtual void Print() const; 
  virtual double Pay() const = 0; // { return 0; }
 private: 
  string firstName_; 
  string lastName_; 
  string jobTitle_; 
  int payPeriods_; 

}; //end Employee class 

} // end CS240 Employees





#endif //EMPLOYEE_H_