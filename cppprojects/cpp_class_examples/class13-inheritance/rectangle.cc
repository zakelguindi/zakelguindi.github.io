//Copyright 2023 Zak Elguindi 
//implement functionality of rectangle.h
#include"rectangle.h"
#include<iostream>
using std::ostream;
using std::cout; 
using std::endl; 

namespace cs240_shapes {

Rectangle::Rectangle(double l, double w) : length_(1), width_(1) { //defaults length and width to 1 
  cout << "In the rectangle constructor" << endl; 
  SetLength(l); 
  SetWidth(w); 
}

void Rectangle::SetLength(double l) {
  if( l > 0) {
    length_ = l; 
  }
}

void Rectangle::SetWidth(double w) {
  if(w > 0) 
    width_ = w; 
}

double Rectangle::Area() const {
  return length_ * width_; 
}

double Rectangle::Perimeter() const {
  return (2 * length_) + (2 * width_); 
}

ostream& operator << (ostream& whereto, const Rectangle& toprint) {
  whereto << "Rectangle length = " << toprint.length_
          << " width = " << toprint.width_; 
  return whereto; 
}


} //end namespace cs240_shapes