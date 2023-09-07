//Copyright 2023 Zak Elguindi 
//Implementation of shortanswerquestion.h class 
#include<string>
using std::string; 
// #include"question.h"
#include"shortanswerquestion.h"
#include<iostream>
using std::cout; 
using std::endl; 

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a)
                                      : Question("?"), answer_("") {
  SetQuestion(q); 
  SetAnswer(a);                          
}

void ShortAnswerQuestion::SetAnswer(string a) {
  if(a.length() > 0)
    answer_ = a; 
}

void ShortAnswerQuestion::Print(bool answer) const {
  cout << "Question: " << GetQuestion() << endl; 
  if(answer == true) {
    cout << "Correct Answer: " << answer_ << endl; 
  }
}

bool ShortAnswerQuestion::CheckAnswer(string answer) const {
  if(answer_ == answer) 
    return true;  
  return false; 
}

} //end namespace csce240_project5