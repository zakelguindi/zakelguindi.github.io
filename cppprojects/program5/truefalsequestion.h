// TrueFalseQuestion should be a child of the Question class

// The class should have a private bool data member that holds whether the
// answer to the question is true or false. Add an accessor and mutator
// function for this data member

// Create an explicit constructor that allows the question and answer to be
// initialized when an object is instantiated. The question and answer
// parameters should have default arguments of "?" and true, respectively.

// Add a Print function that takes a bool parameter: void Print(bool) const;
// This fuction should create 1 or 2 lines of output to the standard output
// device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member.
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by "true" or "false" depending on the
// value of the private data member.
#ifndef _TRUEFALSEQUESTION_H_
#define _TRUEFALSEQUESTION_H_

#include"question.h"
#include<string>
using std::string; 

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
 public: 
  virtual ~TrueFalseQuestion() { }; 
  explicit TrueFalseQuestion(string q = "?", 
                            bool answer = true);
  bool GetAnswer() const { return answer_; }
  void SetAnswer(bool answer); 
  virtual void Print(bool answer) const; 
  bool CheckAnswer(string answer) const; 
 private: 
  bool answer_;
};

} //end CS240_program5 namespace 

#endif // TRUEFALSEQUESTION_H_