//Copyright 2023 Zak Elguindi 
//Define our Set template class 
//set - unordered collection of distinct objects 
//since objects can be of any type - we'll make this a template class 

#ifndef _SET_H_
#define _SET_H_
#include<iostream>
using std::cout; 
using std::endl; 

namespace cs240_set { 

template<class TheType> //applies to the very next definition ("Set" class)
class Set {
 public: 
  Set() {
    size_ = 0; 
    values_ = nullptr; 
  }
  //Destructor 
  ~Set() {
    if(values_ != nullptr) 
      delete [] values_; 
  }
  //copy constructor 
  Set(const Set& tocopy); 
  //assignment operator
  Set& operator = (const Set& tocopy); 
  //pre-conditions the second argument points to a block of at least newSize TheTypes (currently not checking for duplicates) 
  void SetValues(int newSize, const T * newValues) {
    if(newSize < 0)
      return; 
    if(newSize != size_) {
      if(size_ != 0) 
        delete [] values_; //free up old space 
      if(newSize == 0) {
        values_ = nullptr; 
      }
      else 
        values_ = new TheType[newSize]; 
    }
    size_ = newSize;
    //checks for duplicates  
    int position = 0; 
    for(int i=0; i<size_; i++) {
      bool alreadythere = false; 
      for(int j=0; j< position && !alreadythere; j++)
        alreadythere = values[j] == newvalues[i]; 
      if( !alreadythere)
        values[position++] = newvalues[i]; 
    }
    size_ = position; 
  }
  void Print() const {
    cout << "{"; 
    for(int i=0; i<size_; i++)
      cout << values_[i] << (i < size_ -1 ? ", "); //puts commas until it gets to the last one 
    cout << "}" << endl; 
  } 
  
  //is a subset of 
  bool IsASubset( const Set& possible_subset) const {
    bool answer = true; 
    int i=0; 
    while(answer && i < possible_subset.size_) {
      answer = false; 
      for(int j=0; j<size_ && !answer; j++) {
        answer = values_[j] == possible_subset.values_[i]; 
        //i moves through second subset, j moves through first
        //seeing if second matches any in the first, as soon as there's a match, we've found the current one 
      }
      i++; 
    }
    return answer; 
  }
  //Is an element of
  bool IsAnElementOf(const TheType& theValue) const {
    bool found = false; 
    int i=0; 
    while(i < size_ && !found) 
      found = values[i++] == theValue; //stops loop when found is true 
    return found; 
  }
 private: 
  int size_; //cardinality 
  TheType * values_; 
}; //end class Set

} //namespace cs240_set 

#endif // set_h_