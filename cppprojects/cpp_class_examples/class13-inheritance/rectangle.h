//Copyright 2023 Zak Elguindi
//Define the Rectangle class (base class for our inheritance)
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include<iostream>
using std::ostream; 

namespace cs240_shapes {

class Rectangle {
  friend ostream& operator << (ostream& whereto, const Rectangle& toprint); 

 public: 
  explicit Rectangle(double l=1, double w=1); 

  void SetLength(double l); 
  void SetWidth(double w); 
  double GetLength() const { return length_; }
  double GetWidth() const { return width_; }
  double Area() const; 
  double Perimeter() const; 


 private: 
  double length_; 
  double width_; 

}; //end class Rectangle 


} //end namespace cs240_shapes


#endif //end _RECTANGLE_H_