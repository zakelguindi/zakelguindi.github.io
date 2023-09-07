//Copyright 2023 Zak Elguindi 
//Define the School class 

#ifndef _SCHOOL_H_
#define _SCHOOL_H_

class School { 
 public: 
  School(); 
  /*School() { //def constructor
    enrollment_ = 100; 
  } */
  int GetEnrollment() const { return enrollment_;}
  void SetEnrollment(int x); 
 private:
  int enrollment_; 
};

#endif //_SCHOOL_H_