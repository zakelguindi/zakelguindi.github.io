//Copyright 2023 Zak Elguindi 
//Implementation of truefalsequestion.h

#include<string>
using std::string; 
#include"question.h"
#include"truefalsequestion.h"
#include<iostream>
using std::cout; 
using std::endl; 

namespace csce240_program5 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool answer) 
                                    : Question("?"), answer_(true) {
  SetAnswer(answer); 
  SetQuestion(q); 
}

void TrueFalseQuestion::SetAnswer(bool answer) {
  if(answer == false) 
    answer_ = answer; 
  else 
    answer_ = true; 
}

void TrueFalseQuestion::Print(bool answer) const {
  cout << "Question: " << GetQuestion() << endl; 
  if(answer == true) {
    cout << "Correct Answer: ";
    if(answer_ == true) 
      cout << "true"; 
    if(answer_ == false) 
      cout << "false";
    cout << endl; 
  }
}

bool TrueFalseQuestion::CheckAnswer(string answer) const {
  if(answer == "true" || answer == "True" || answer == "TRUE") {
    if(answer_) 
      return true; 
  } else if(answer == "false" || answer == "False" || answer == "FALSE") {
    if(!answer_) 
      return true; 
  }
  return false; 
}

/**
 * need to implement checkanswers method in t/f, multiple choice, and short answer 
 * make it a tailored version of it for each class
 * then, appropriately call it in checkstudentanswers.cc
 * */

} //end namespace csce240_program5