//Copyright 2023 Zak Elguindi 

#include<iostream>
#include"length.h"
using std::cout; 
using std::endl; 
#include<string>
using std::string; 
#include<ostream>
using std::ostream; 

Length::Length(const double& value, const string& units)
  : value_(value), units_(units) {
  SetValue(value); 
  SetUnits(units); 
}

void Length::SetUnits(string units) {
  if(units == "inches" || units == "centimeters") {
    units_ = units; 
  } else {
    units_ = "inches"; 
  } 
}

void Length::SetValue(const double& value) {
  if(value > 0) {
    value_ = value; 
  } else if(value_ > 0) {
    value_ = value_; 
  } else {
    value_ = 0; 
  }
}

void Length::Convert(const string& units){
  // cout << "Value: " << value_ << endl; 
  if(units == units_) {
    return; 
  }
  if(units == "inches") {
    // inches to cm 
    value_ /= 2.54; 
    units_ = "inches";
  } else if(units == "centimeters") {
    //cm to inches
    value_ *= 2.54; 
    units_ = "centimeters"; 
  }
}

bool Length::operator == (Length rightOperand) const{
  if(units_ == rightOperand.GetUnits()) {
    //units are the same, don't convert 
    if(value_ == rightOperand.GetValue()) {
      return true; 
    }
  } else {
    //units are different
    rightOperand.Convert(units_); 
    if(value_ == rightOperand.GetValue()) {
      return true; 
    }
  }
  return false; 
}

bool Length::operator < (Length rightOperand) const {
  rightOperand.Convert(units_); 
  if(value_ < rightOperand.GetValue()) {
    return true; 
  }
  return false; 
}

ostream& operator << (ostream& whereto, const Length& toprint) {
  whereto << toprint.GetValue() << " " << toprint.GetUnits(); 
  return whereto; 
}

Length Length::operator + (Length rightOperand) const {
  rightOperand.Convert(units_); 
  int returnvalue = rightOperand.GetValue() + value_; 
  string units = rightOperand.GetUnits(); 
  Length l = Length(returnvalue, units); 
  return l; 
}