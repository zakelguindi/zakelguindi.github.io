// Copyright 2023 Zak Elguindi
// Define the FactCheckedStatement class as a child of the Sentence class
#ifndef _FACTCHECKEDSTATEMENT_C_
#define _FACTCHECKEDSTATEMENT_C_
#include"sentence.h"
#include<string>
using std::string;
#include<iostream>
using std::ostream;

// Add a constructor that takes a string parameter for the statement and
// and a double parameter for the verified truth of the statement (a value
// between 0 and 1, inclusive).
// Provide a default argument of 0 for the double parameter.
// If the string argument is not a valid statement (doesn't start with an
// uppercase alphabetic character or doesn't end with a period), the statement
// should default to "This is an unverified statement."




// Overload the assignment operator.
// If the string (the right operand) begins with an uppercase alphabetic
// character and ends with a period, the FactCheckedStatement should be
// set to that string and the data member holding the truth of the statement
// should be set to 0.
// If the right operand does not start with an uppercase alphabetic character
// or it does not end with a period, the FactCheckedStatement object should
// remain unchanged by the operation.


// Add an accessor function for the double data member holding the truth
// of the statement.

// Add a mutator function for the double data member holding the truth of
// the statement that takes a double parameter.
// If the argument sent to the function is a value between 0 and 1, inclusive,
// the data member should be set to the argument's value.
// If the argument sent to the function is not between 0 and 1, the data
// member should remain unchanged by the function call.


// Overload the stream insertion operator to output a FactCheckedStatement
// object. The output should be the statement string followed by percent
// truth in parenthesis.
// For example, if the FactCheckedStatement x is
// "The third exam/project for CSCE240 is due by 11:59pm on May 2." with a
// truth value of 1, then cout << x should print
// "The third exam/project for CSCE240 is due by 11:59pm on May 2. (100% true)"
// to the standard output device.
// See testoutput.cc and correctoutput.txt for additional examples of the
// expected output for example FactCheckedStatement objects.

namespace Project3Problem2 {

class FactCheckedStatement : public Sentence {
  friend ostream& operator << (ostream& whereto,
                              const FactCheckedStatement& toprint) {
    int truth = toprint.truth_ * 100;
    // cout << "truth: " << truth << endl;
    string t = std::to_string(truth);
    // whereto << toprint << " (" << truth << "% true)";
    string statement = toprint;
    statement +=  " (";
    statement += t;
    statement += "% true)";
    whereto << statement;
    return whereto;
    // error: all paths through this function will call itself
  }

 public:
  explicit FactCheckedStatement(string statement, double truth = 0)
                                : Sentence(statement), truth_(0) {
    string::operator = ("This is an unverified statement.");
    char start = statement[0];
    char end = statement[statement.length() -1];
    if ((start >= 'A' && start <= 'Z') && end == '.') {
      string::operator = (statement);
      // *this = statement;
    }
    // *this = Sentence(statement);
    SetTruth(truth);
    // cout << "Statement: " << statement << ", truth: " << truth << endl;
  }
  FactCheckedStatement& operator = (const string& rightoperand) {
    char start = rightoperand[0];
    char end = rightoperand[rightoperand.length() - 1];
    if ((isupper(start) && (end == '.'))) {
      // is valid
      string::operator = (rightoperand);
      return *this;  // might not need this line
    }
    return *this;
  }
  double GetTruth() const { return truth_; }
  void SetTruth(double truth) {
    if (truth >= 0 && truth <= 1) {
      // truth is valid
      truth_ = truth;
    } else {
      truth_ = 0;
    }
  }

 private:
  double truth_;
};

}  // end namespace Project3Problem2

#endif  // _FACTCHECKEDSTATEMENT_C_

