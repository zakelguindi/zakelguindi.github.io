//Copyright 2023 Zak Elguindi 
//define a class to hold a Polynomial in one variable 
//ex: 3x^2 - 5x + 1
//hold data members for the degree of the polynomial object and its coefficient 
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include<iostream>
using std::ostream; 

class Polynomial { 
  //the stream insertion operator can't be a member of our class bc the left operand isn't a polynomial 
  //we'll make it a friend, giving it access to the private members of our class 
  friend ostream& operator << ( ostream& whereto, const Polynomial& toprint);//takes outputstream reference (ostream)- send by reference(&) to save memory/time by not calling constructor
 
 public: 
 //will make constructor that can be called with exactly one argument
 //explicit so that objects are onluy created when we explicitly call the constructor 
  explicit Polynomial(int degree=0); //can take one argument so it's explicit

  //since left operand is a polynomial, we can make this operator a member of our Polynomial class. 
  /*
  operator needs to return a Polynomial to have it work for x = y = z. 
  */
  Polynomial& operator = (const Polynomial& rightOperand); 
  Polynomial(const Polynomial& tocopy);
  ~Polynomial() { delete [] coefficients_;  }//ensures that space is freed up 

  void SetDegree(int degree); 
  static void SetVariable(char var); 

  //overload the [] operator to obtain coefficient of a particular term 
  double& operator [] (int term); 
  double operator [] (int term) const; //signature is name + parameter list- every function must have one

  //overload the + operator - since the left operand is a Polynomial, the operator can be a member of the Polynomial class 
  Polynomial operator + (const Polynomial& rightoperand) const; //const method bc x won't change, const rightoperand bc y won't change (in x + y)
  

 private: 
  int degree_; //nonnegative 
  double * coefficients_; //pointer will dynamically allocate memory for coefficients - points to a block of degree_ + 1 doubles 
  static char variable_; 
}; 

#endif //end _POLYNOMIAL_H_