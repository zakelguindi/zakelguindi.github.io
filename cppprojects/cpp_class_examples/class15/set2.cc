//Copyright 2023 Zak Elguindi 
//source file with the implementation of Set class member function 
#include"set.h"

namespace cs240_set {

template<class TheType> 
Set<TheType>::Set(const Set& tocopy) {
  size_ = 0; 
  values_ = nullptr; 
  SetValues(tocopy.size_, tocopy.values_);
}

template<class TheType>
Set<TheType>& Set<TheType>::operator= (const Set& tocopy) {
  SetValues(tocopy.size_, tocopy.values_); 
  return *this; //return newly updated object the operator was called on 
}

} // end namespace cs240_set 