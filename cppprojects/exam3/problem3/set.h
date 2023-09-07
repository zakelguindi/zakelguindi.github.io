// Copyright 2023 CSCE240 (bhipp)
// Copyright 2023 Zak Elguindi

// Define our Set template class
// set - unordered (the order of the values doesn't matter) collection of
//       distinct objects (since the objects can be of any type - we'll make
//       this a template class
#ifndef _SET_H_
#define _SET_H_

#include<iostream>
using std::cout;
using std::endl;

namespace Project3Problem3 {

template<class TheType>
class Set {
 public:
  // default constructor
  explicit Set(int size = 0, const TheType * values = nullptr) {
    size_ = 0;
    values_ = nullptr;
    SetValues(size, values);
  }

  // copy constructor
  Set(const Set& to_copy) {
    size_ = 0;
    values_ = nullptr;
    SetValues(to_copy.size_, to_copy.values_);
  }

  // destructor
  ~Set() {
    if ( values_ != nullptr )
      delete [] values_;
  }

  // assignment operator
  Set& operator = (const Set& to_copy) {
    SetValues(to_copy.size_, to_copy.values_);
    return *this;  // return the newly updated object the operator
                  // was called on
  }

  // SetValues function
  // pre-conditions the second argument points to a block of at least
  //                new_size TheTypes (currently not checking for
  //                duplicates)
  void SetValues(int new_size, const TheType * new_values) {
    if ( new_size < 0 )
      return;
    if ( new_size != size_ ) {
      if ( size_ != 0 )
        delete [] values_;
      if ( new_size == 0 )
        values_ = nullptr;
      else
       values_ = new TheType[new_size];
    }
    size_ = new_size;
    int position = 0;
    for ( int i = 0; i < size_; ++i ) {
      bool already_in_there = false;
      for ( int j = 0; j < position && !already_in_there; ++j )
         already_in_there = values_[j] == new_values[i];
      if ( !already_in_there )
        values_[position++] = new_values[i];
     }
     size_ = position;
  }

  // Print function to display values at the standard output device
  void Print() const {
    cout << "{";
    for ( int i = 0; i < size_; ++i )
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}" << endl;
  }

  // Is a Subset of
  bool IsASubset(const Set& possible_subset) const {
    bool answer = true;
    int i = 0;
    while ( answer && i < possible_subset.size_ ) {
      answer = false;
      for ( int j = 0; j < size_ && !answer; ++j ) {
        answer = values_[j] == possible_subset.values_[i];
      }
      ++i;
    }
    return answer;
  }

  // is an element of
  bool IsAnElementOf(const TheType& the_value) const {
    bool found = false;
    int i = 0;
    while ( i < size_ && !found )
      found = values_[i++] == the_value;
    return found;
  }

  int GetCardinality() const { return size_; }

  // Implement the Intersection function whose prototype is given below.
  // The function should return the intersection of the two sets. Recall, the
  // intersection of two sets is the set of all elements the two sets have in
  // common.
  // For example, if set1 is the set { 1, 8, 2, 6, 3 } and
  //                 set2 is the set { 6, 4, 1 } then
  //                 set1.Intersection(set2) should return the set { 1, 6 }
  // For example, if set1 is the set { 'a', 'c' } and
  //                 set2 is the set { 'r, 'm', 'l', 't' } then
  //                 set1.Intersection(set2) should return the set {}
  // For example, if set1 is the set { 9.8, 2.7 } and
  //                 set2 is the set { 2.7, 4.16, 9.8 } then
  //                 set1.Intersection(set2) should return the set { 9.8, 2.7 }
  // function prototype: Set Intersection(const Set& right) const;
  Set Intersection(const Set& right) const {
    // intersects if there are any similarities across sets.
    // add it to a pointer? if testing goes wrong,
    // add it to an array and just resize it
    // TheType * intersections;
    int k = 0;
    for (int i = 0; i < right.size_; i++) {
      for (int j = 0; j < size_; j++) {
        if (values_[j] == right.values_[i]) {
          // intersections[k] = values_[j];
          k++;
        }
      }
    }
    TheType intersections[k];
    int l = 0;
    for (int i = 0; i < right.size_; i++) {
      for (int j = 0; j < size_; j++) {
        if (values_[j] == right.values_[i]) {
          intersections[l] = values_[j];
          l++;
        }
      }
    }
    // for(int i=1; i<k; i++) {
    //   if(intersections[i] == intersections[i-1]) {
    //     //equal to the one before it
    //     delete [] intersections[i]; //delete current
    //     i--;
    //   }
    // }
    // Set returnval = Set(k, intersections);
    // for(int i=0; i<k; i++) {
    //   returnval.values_[k] = intersections[k];
    // }
    return Set(k, intersections);
  }



  // The == operator should return true if the set on the left on the left
  // and the set on the right contain exactly the same elements (values) and
  // false otherwise.
  // For example, if set1 is the set {1, 2, 3} and
  //                 set2 is the set {2, 1, 3}
  //                 set1 == set2 should return true
  // For example, if set1 is the set {'a', 'b', 'x'} and
  //                 set2 is the set {'x', 'b'}
  //                 set1 == set2 should return false
  // prototype: bool operator == (const Set& right) const;
  bool operator == (const Set& right) const {
    // make an int, if numbers are the same, add to it.
    // if size = int, return true
    int sameValues = 0;
    for (int i = 0; i < right.size_; i++) {
      for (int j = 0; j < size_; j++) {
        if (right.values_[i] == values_[j]) {
          sameValues++;
        }
      }
    }
    if (sameValues == size_) {
      return true;
    } else {
      return false;
    }
  }

 private:
  int size_;  // cardinality / cardinal number
  TheType * values_;
};  // class Set

}  // namespace Project3Problem3

#endif  // _SET_H

