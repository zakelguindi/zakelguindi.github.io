//Copyright 2023 Zak Elguindi 
//implementation of the multiplechoicequestion.h class 
#include<string>
using std::string; 
#include"question.h"
#include"multiplechoicequestion.h"
#include<iostream>
using std::cout; 
using std::endl; 

namespace csce240_program5 {

MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int options, 
                                                string * answers, bool * correct)
                                                : Question(q), options_(0) {
  //checks if first three are empty
  SetQuestion(q); 
  SetOptions(options); 
  answers_ = new string[options_]; 
  correct_ = new bool[options_]; 
  //if correct call the set functions
  //do scenarios for both null answers and null corrects 
  if(answers == nullptr) {
    //if null, set it to ""
    for(int i=0; i<options_; i++)
      answers_[i] = ""; 
  } else {
    // it's correct
    for(int i=0; i<options_; i++) 
      answers_[i] = answers[i]; 
  }

  //correct is null 
  if(correct == nullptr) {
    //set it to true
    for(int i=0; i<options_; i++) 
      correct_[i] = true; 
  } else {
    for(int i=0; i<options_; i++) 
      correct_[i] = correct[i]; 
  }

/*
  if(q != "?" && options > 0 && answers != nullptr && correct != nullptr) {
    SetAnswerChoices(options, answers, correct); 
  } else if(correct == nullptr && answers == nullptr) {
    answers_ = new string[options]; 
    for(int i=0; i<options; i++) {
      answers_[i] = ""; 
    }
    correct_ = new bool[options]; 
    for(int i=0; i<options; i++) {
      correct_[i] = true; 
    } 
    SetAnswerChoices(options, answers_, correct_); 
  }
  else {
    if(answers == nullptr) {
      answers_ = new string[options]; 
      for(int i=0; i<options; i++) {
        answers_[i] = ""; 
      }
  } 
    if(correct == nullptr) {
      correct_ = new bool[options]; 
      for(int i=0; i<options; i++) {
        correct_[i] = true; 
      } 
    }
    SetAnswerChoices(options, answers_, correct_); 
  }
  */
}

MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& copyQuestion) {
  SetQuestion(copyQuestion.GetQuestion()); 
  options_ = copyQuestion.options_; 
  answers_ = new string[copyQuestion.options_];
  correct_ = new bool[copyQuestion.options_];
  for(int i=0; i<copyQuestion.options_; i++) {
    answers_[i] = copyQuestion.answers_[i]; 
    correct_[i] = copyQuestion.correct_[i]; 
  }
}

void MultipleChoiceQuestion::SetAnswerChoices(int options, string * answers, bool * correct) {
  //need to allocate/deallocate memory for it
  SetOptions(options); 
  delete [] correct_; 
  delete [] answers_; 
  answers_ = new string[options_]; 
  correct_ = new bool[options_]; 
  if(answers != nullptr) {
    for(int i=0; i<options_; i++) {
      answers_[i] = answers[i]; 
    }
  } else {
    for(int i=0; i<options_;i++)
      answers_[i] = ""; 
  }
  if(correct != nullptr) {
    for(int i=0; i<options; i++)
      correct_[i] = correct[i]; 
  } else {
    for(int i=0; i<options_; i++) 
      correct_[i] = true; 
  }
}

void MultipleChoiceQuestion::Print(bool answer) const {
  cout << "Question: " << GetQuestion() << endl; 
  cout << "Answer Choices:" << endl; 
  for(int i=0; i<options_; i++) {
    cout << answers_[i]; 
    if(answer == true) {
      cout << " - "; 
      if(correct_[i] == true)
        cout << "correct"; 
      else 
        cout << "incorrect";
    }
    cout << endl; 
  }
}

void MultipleChoiceQuestion::SetOptions(int options) {
  if(options > 0)
    options_ = options; 
}

MultipleChoiceQuestion& MultipleChoiceQuestion::operator= (const MultipleChoiceQuestion&
                                                             rightOperand) {
  if(options_ != rightOperand.options_) {
    //overwrite options_ 
    SetQuestion(rightOperand.GetQuestion()); 
    options_ = rightOperand.options_; 
    //delete pointer memory 
    delete [] answers_; 
    delete [] correct_; 
    answers_ = new string[options_]; 
    correct_ = new bool[options_]; 
  }
  for(int i=0; i<options_; i++) {
    answers_[i] = rightOperand.answers_[i]; 
    correct_[i] = rightOperand.correct_[i]; 
  }
  return *this; 
}

bool MultipleChoiceQuestion::CheckAnswer(string answer) const {
  for(int i=0; i<options_; i++) {
    if(answer == answers_[i]) 
      return correct_[i]; 
  }
  return false; 
}

} //end namespace csce240_program5