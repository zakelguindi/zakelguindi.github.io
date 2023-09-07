//Copyright 2023 Zak Elguindi
//Define Temperature class
#ifndef _TEMPERATURE_H_ 
#define _TEMPERATURE_H_ 

#include<string>  // class in the standard library
using std::string; // string is in std namespace 

class Temperature {
 public: 
  //constructor
  //if we have a constructor that can take exactly one arg, we'll make it explicit 
  //means the compiler can't create a Tempearture out of a double without us explicitly telling it to do so. 
  explicit Temperature(double v = 0, string u = "Celsius");

  //destructor 
  ~Temperature(); 

  //t1 < t2 is same as t1.operator(t2); 
  bool operator < ( const Temperature& rightoperand) const; 


  //accessors: 
  double GetValue() const { return value_; } 
  string GetUnits() const { return units_; }

  // mutators:
  void SetValue(double v); 
  void SetUnit(string u);  

  void Print() const; 
  void Convert(string newunits); 

 private: 
  double value_; 
  //composition- when a class " has a(n) " object of another class as a data member 

  string units_; 
};


#endif //_TEMPERATURE_H_ 