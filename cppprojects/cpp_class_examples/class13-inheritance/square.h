//Copyright 2023 Zak Elguindi
//Define the Square derived class 
#ifndef _SQUARE_H_
#define _SQUARE_H_

#include"rectangle.h"

namespace cs240_shapes {

class Square : public Rectangle { //use this format for creating inheritance classes 
  friend ostream& operator << (ostream& whereto, const Square& s); 
 public: 
  explicit Square(double side=1); //explicit since it can take exactly one arg 

  //redefine- write a function in the derived class with the same prototype as an existing function in the base calss 
  void SetLength(double side); 
  void SetWidth(double side);
};



} //end cs240_shapes namespace 


#endif //end square_h_