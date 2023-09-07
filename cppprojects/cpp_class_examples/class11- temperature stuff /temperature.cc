//Copyright 2023 Zak Elguindi 
//Implement the functionality of the Temperature class 
#include"temperature.h" 
#include<iostream>
#include<string> 
using std::string; 
using std::cout; 
using std::endl; 


bool Temperature::operator<(const Temperature& rightoperand) const{
  if(units_ == rightoperand.units_) { 
    return value_ < rightoperand.value_; 
  }
  Temperature leftCopy(*this); //every object knows/has its address in "this" pointer. use *this to get that value of the object that the member function is being called on. 
  leftCopy.Convert(rightoperand.units_); 
  return leftCopy.value_ < rightoperand.value_; 
}

//toy example to show when destructor is called 
//this will be important if we have any housecleaning to do when we're finished with an object (ie pointers to dynamic memory as data members)
Temperature::~Temperature() {
  cout << "Destructor called for " << value_ << " " << units_ << endl; 
}

//member initializer list comes between constructor's parameters () and body {} 
Temperature::Temperature(double v, string u) : value_(0), units_("Celsius"){
  // value_ = 0; 
  // units_ = "Celsius"; 
  SetValue(v); 
  SetUnit(u); 
}

void Temperature::SetValue(double v) {
  value_ = v; 
}

void Temperature::SetUnit(string u) {
  if( u == "Fahrenheit" || u == "Celsius" || u == "Kelvin" ) 
    units_ = u; 
}

void Temperature::Print() const {
  cout << value_ << " degrees " << units_ << endl; 
}

void Temperature::Convert(string u) {
  if(units_ == u) {
    return; 
  } 
  if(units_ == "Fahrenheit" ) {
    if(u == "Celsius") {
      value_ = 5 / 9.0 * (value_ - 32); 
      units_ = u; 
    } else if(u == "Kelvin") {
      value_ = 5 / 9.0 * (value_-32) - 273.15;
      units_ = u; 
    }
  } else if(units_ == "Celsius" ) {
    if(u == "Fahrenheit") {
      value_ = 9 / 5.0 * value_ + 32; 
      units_ = u; 
    } else if( u == "Kelvin" ) {
      value_ -= 273.15; 
      units_ = u; 
    }
  } else {
    if(u == "Fahrenheit") {
      value_ = 9 / 5.0 * (value_ + 273.15 ) + 32; 
      units_ = u; 
    } else if(u == "Celsius") {
      value_ += 273.15; 
      units_ = u; 
    } 
  }
}