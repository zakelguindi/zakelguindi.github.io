//Copyrigth 2023 Zak Elguindi 
//implement functionality of our Polynomial class 
#include"polynomial.h"
#include<iostream>
using std::ostream; 

//important parts: copy constructor, assignment operator, and destructor 

//copy constructor for instantiating a new object as a copy of an existing object
Polynomial::Polynomial(const Polynomial& tocopy) {
  degree_ = tocopy.degree_; 
  coefficients_ = new double[degree_ + 1]; 
  for(int i=0; i<=degree_; i++) {
    coefficients_[i] = tocopy.coefficients_[i]; //
  }
}

double& Polynomial::operator [] (int term) {
  if(term < 0) // need to handle this in some way 
    term = 0; 
  if(term > degree_) {
    double * newcoefficients = new double [ term + 1]; 
    for(int i=0; i<degree_; i++) {
      newcoefficients[i] = coefficients_[i]; 
    }
    for(int j= degree_ + 1; j < term; j++) {
      newcoefficients[j] = 0; 
    }
    degree_ = term; 
    delete [] coefficients_; 
    coefficients_ = newcoefficients; 
  }
  return coefficients_[term]; 
}

char Polynomial::variable_ = 'z'; 

void Polynomial::SetVariable(char var) {
  if( var >= 'a' && var <= 'z') {
    variable_ = var; 
  }
}

Polynomial Polynomial::operator + (const Polynomial& rightoperand) const {
  int maxdegree = (degree_ > rightoperand.degree_ ? degree_ : 
                    rightoperand.degree_ );
  Polynomial returnvalue(maxdegree); 
  for(int i=0; i<= maxdegree; i++) {
    if(i > degree_) {
      returnvalue[i] = (*this)[i] + rightoperand[i]; 
    } else if(i > rightoperand.degree_)
      returnvalue[i] = (*this)[i]; 
    else 
      returnvalue[i] = (*this)[i] + rightoperand[i]; 
  } 
  return returnvalue; 
}

//no friend keyword here- only the class can grant friendship 
ostream& operator << (ostream& whereto, const Polynomial& toprint) {
  for(int i = toprint.degree_; i >= 0; i--) {
    if(toprint.coefficients_ != 0) {
      whereto << toprint.coefficients_[i];
      if(i > 0)
        whereto << "x";  
      if(i > 1) 
        whereto <<"^" << i; 
      if( i > 0) 
        whereto << " + "; 
    }
  }
  return whereto; 
}

Polynomial::Polynomial(int degree) {
  if(degree < 0) {
    degree = 0; 
  }
  degree_ = degree; 
  coefficients_ = new double [degree_ + 1]; // "new" dynamically allocates memory 
  // the check below is for older compilers
  if(coefficients_ == nullptr)  
    return; 
  
  for(int i=0; i<= degree_; i++) {
    coefficients_[i] = 1; 
  }
}

//this function is called on existing objects that have memory allocated for the coefficients_ data member
void Polynomial::SetDegree(int degree) {
  if ( degree < 0 || degree == degree_) {
    return; 
  }

  delete [] coefficients_; //prevents memory leaks- don't forget 
  /**
   * deleted previous coefficients 
   * 
   * */

  //once memory is freed, it's save to make coefficients point elsewhere
  degree_ = degree; 
  coefficients_ = new double [degree_ + 1]; // "new" dynamically allocates memory 
  // the check below is for older compilers
  if(coefficients_ == nullptr)  
    return; 
  
  for(int i=0; i<= degree_; i++) {
    coefficients_[i] = 1; 
  }
}

Polynomial& Polynomial::operator = (const Polynomial& rightOperand) {
  if(degree_ != rightOperand.degree_) {
    degree_ = rightOperand.degree_; 
    delete [] coefficients_; //SUPER IMPORTANT 

    coefficients_ = new double[degree_ + 1]; 
  }
  for(int i=0; i<=degree_; i++) {
    coefficients_[i] = rightOperand.coefficients_[i]; 
    //this is the address of the object the function was called on (the left operand), so returning *this returns the left operand
    return *this; 
  }
}