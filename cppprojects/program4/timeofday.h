//Copyright 2023 Zak Elguindi
// Define a TimeOfDay class that has private integer data members for the
//    hour (24 hour value)
//    minute
//    second
// The class should ensure that the data members always remain in a consistent
// state.


// Add a constructor to allow the user to initialize the hour, minute,
// and second, in that order, with default arguments of 0
// If an argument value is invalid, the corresponding data member should be
// initialized to zero. For example, TimeOfDay(9, 87, 13) should initialize
// the hour to 9, the minute to 0, and the second to 13.


// Add mutator functions SetHour, SetMinute, and SetSecond that set the
// data member if the argument is valid, and leave the data member unchanged
// if the argument is invalid.


// Add accessor functions GetHour, GetMinute, and GetSecond that return
// a copy of the value of the corresponding data member.


// Add a Print function that will output the TimeOfDay object to the standard
// output device using cout, ending with endl (to flush the output buffer and
// go to the next line).
// The Print function should take two bool parameters for whether or not to
// display the time in military time (i.e. 24 hour format) and whether or
// not to display the seconds value.
// Both parameters should have default arguments of false.
// If the first argument is true, the time should print in military time (24
//  hour format), and if the first argument is false, the time should print
//  in a.m./p.m. format.
//  For example 13:00:00 in military time is equivalent to 01:00:00 p.m.
//          and 07:00:00 in military time is equivalent to 07:00:00 a.m.
// If the second argument is true, the output should display the seconds
//  value and if the second argument is false, the output should omit (drop,
//  don't round) the seconds component of the time.
// e.g. Print() output will be formated as hh:mm a.m. or hh:mm p.m.
//      Print(true) output will be formated as hh:mm
//      Print(true, true) output will be formated as hh:mm:ss
//      Print(false, true) output will be formatted as
//                         hh:mm:ss a.m. or hh:mm:ss p.m.

#ifndef _TIMEOFDAY_H_
#define _TIMEOFDAY_H_

class TimeOfDay {
 public: 
  explicit TimeOfDay(const int& hour = 0, const int& minute = 0, const int& second = 0); 

  void SetHour(const int& h); 
  void SetMinute(const int& m); 
  void SetSecond(const int& s); 

  int GetHour() const { return hour_;}
  int GetMinute() const { return minute_; } 
  int GetSecond() const { return second_;} 

  void Print(const bool& militaryTime = false, const bool& displaySeconds = false); 

 private: 
  int hour_ = 0; 
  int minute_ = 0;  
  int second_ = 0; 
};

#endif
