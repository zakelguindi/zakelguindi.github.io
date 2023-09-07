// Copyright 2023 bhipp
// implement the functionality of our Polynomial class
#include"polynomial.h"
#include<iostream>
using std::ostream;

char Polynomial::variable_ = 'z';

void Polynomial::SetVariable(char var) {
  if ( var >= 'a' && var <= 'z' )
    variable_ = var;
}

double& Polynomial::operator [] (int term) {
  if ( term < 0 )  // need to handle this in some way
    term = 0;
  if ( term > degree_ ) {
    double * newcoefficients = new double[term + 1];
    for ( int i = 0; i <= degree_; ++i )
      newcoefficients[i] = coefficients_[i];
    for ( int j = degree_ + 1; j <= term; ++j )
      newcoefficients[j] = 0;
    degree_ = term;
    delete [] coefficients_;
    coefficients_ = newcoefficients;
  }
  return coefficients_[term];
}

double Polynomial::operator [] (int term) const {
  if ( term < 0 )  // need to handle this in some way
    term = 0;
  if ( term > degree_ )
    term = degree_;  // may revisit this to resize the Polynomial...
  return coefficients_[term];
}

// copy constructor for instantiating a new object as a copy of an existing
// object
Polynomial::Polynomial(const Polynomial& tocopy) {
  degree_ = tocopy.degree_;
  coefficients_ = new double[degree_ + 1];
  for ( int i = 0; i <= degree_; ++i )
    coefficients_[i] = tocopy.coefficients_[i];
}


Polynomial& Polynomial::operator = (const Polynomial& rightoperand) {
  if ( degree_ != rightoperand.degree_ ) {
    degree_ = rightoperand.degree_;
    // this is  what would be done by default, which is no good
    // coefficients_ = rightoperand.coefficients_;
    delete [] coefficients_;
    coefficients_ = new double[degree_ + 1];
  }
  for ( int i = 0; i <= degree_; ++i )
    coefficients_[i] = rightoperand.coefficients_[i];

  // this is the address of the object the function was called on (the left
  // operand), so returning *this returns the left operand
  // x = y = z;    y = z;  x = y;
  return *this;
}


// no friend keyword here. only the class can grant frienship
ostream& operator << (ostream& whereto, const Polynomial& toprint) {
  for ( int i = toprint.degree_; i >= 0; --i ) {
    whereto << toprint.coefficients_[i];
    if ( i > 0 )
      whereto << Polynomial::variable_;  // toprint.variable_;
    if ( i > 1 )
      whereto << "^" << i;
    if ( i > 0 )
      whereto << " + ";
  }
  return whereto;
}

Polynomial::Polynomial(int degree) {
  if ( degree < 0 )
    degree = 0;
  degree_ = degree;
  coefficients_ = new double[degree_ + 1];
  // the check below is for older compilers
  if ( coefficients_ == nullptr )
    return;
  for ( int i = 0; i <= degree_; ++i )
    coefficients_[i] = 1;
}

// this function is called on existing objects that have memory allocated
// for the coefficients_ data member
void Polynomial::SetDegree(int degree) {
  if ( degree < 0 || degree == degree_ )
    return;

  // the line below is super important and easy to forget since no compile
  // time error messages will be generated if it's missing
  // free up the old reserved memory in order to prevent a memory leak
  delete [] coefficients_;

  // once the memory is freed, it's safe to make coefficients point elsewhere
  degree_ = degree;
  coefficients_ = new double[degree_ + 1];
  // the check below is for older compilers
  if ( coefficients_ == nullptr )
    return;
  for ( int i = 0; i <= degree_; ++i )
    coefficients_[i] = 1;
}




