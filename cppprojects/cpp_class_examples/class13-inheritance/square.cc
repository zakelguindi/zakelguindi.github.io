//Copyright 2023 Zak Elguindi 
//implement the functionality of the Square class 
#include"square.h"
#include"rectangle.h" 
using std::ostream; 
using std::cout; 
using std::endl; 

namespace cs240_shapes {

ostream& operator << (ostream& whereto, const Square& s) {
  whereto << "Square with side length " << s.GetLength(); 
  // whereto << static_cast<Rectangle>(s); // casting a derived class obj as a base class is a perfectly valid operation in order to call the base class version of a method 
  return whereto; //have to staticly cast s as a rectangle (purely an example though)
}

Square::Square(double side) : Rectangle(side, side) { //initializes it as a rectangle
  cout << "In the square constructor" << endl; 
  //SetLength(side); 
  //SetWidth(side); 
  //lines 13,14 aren't needed because we initialize in line 11
  
}

void Square::SetLength(double side) {
  //length_ = width_ = side - doesn't work 
  Rectangle::SetWidth(side); 
  Rectangle::SetLength(side); 
}

void Square::SetWidth(double side) {
  Rectangle::SetLength(side); 
  Rectangle::SetWidth(side); 
}

} //end namespace cs240_shapes 