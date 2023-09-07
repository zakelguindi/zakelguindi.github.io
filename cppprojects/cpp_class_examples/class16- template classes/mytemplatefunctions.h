// Copyright 2023 bhipp
// some useful template functions
#ifndef _MY_TEMPLATE_FUNCTIONS_H_
#define _MY_TEMPLATE_FUNCTIONS_H_

namespace csce240_template_functions {

template<class T>
void SwapValues(T& x, T& y) {  // expected cpplint message - no worries
  T temp = x;
  x = y;
  y = temp;
}

// our quick sort function
template<class T>
void QuickSort(T the_array[], int bottom, int top) {
  if ( bottom >= top ) return;
  int find_bigger = bottom + 1, find_smaller = top;
  while ( find_bigger < find_smaller ) {
    while ( find_bigger < top && the_array[find_bigger] <= the_array[bottom] )
      ++find_bigger;
    while ( find_smaller > bottom &&
            the_array[find_smaller] >= the_array[bottom] )
      --find_smaller;
    if ( find_bigger < find_smaller )
      SwapValues(the_array[find_bigger], the_array[find_smaller]);
  }
  if ( the_array[bottom] > the_array[find_smaller] )
    SwapValues(the_array[bottom], the_array[find_smaller]);
  QuickSort(the_array, bottom, find_smaller - 1);
  QuickSort(the_array, find_smaller + 1, top);
}


}  // namespace csce240_template_functions

#endif  // _MY_TEMPLATE_FUNCTIONS_H_
