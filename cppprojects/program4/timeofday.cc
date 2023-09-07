//Copyright 2023 Zak Elguindi

#include"timeofday.h"
#include<iostream>
#include<iomanip> 
using std::cout; 
using std::endl; 

TimeOfDay::TimeOfDay(const int& hour, const int& minute, const int& second) {
  if(hour >= 0 && hour < 24) { SetHour(hour); }
  if(minute >= 0 && minute < 60) { SetMinute(minute); }
  if(second >= 0 && second < 60) {SetSecond(second); }
  //should just set every variable correctly. 
}

void TimeOfDay::SetHour(const int& h) {
  if(h >= 0 && h < 24) {
    hour_ = h; 
  }
}

void TimeOfDay::SetMinute(const int& m) {
  if(m >= 0 && m < 60) {
    minute_ = m; 
  }
}

void TimeOfDay::SetSecond(const int& s) {
  if(s >= 0 && s < 60) {
    second_ = s; 
  } 
}

void TimeOfDay::Print(const bool& militaryTime, const bool& displaySeconds) {
  //outputs timeofday to std output. 
  //takes two bool parameters for military/standard time AND seconds included (both default false) 
  //Print() {false, false} = hh:mm a.m. or p.m.
  //Print(true) {true, false} = hh:mm
  //Print(true, true) = hh:mm:ss
  //Print(false, true) = hh:mm:ss a.m. or hh:mm:ss p.m.

  if(!militaryTime) { 
    //standard time
    cout << std::setw(2) << std::setfill('0') << hour_%12 << ":" << std::setw(2) << std::setfill('0') << minute_; 
    if(displaySeconds) {
      //false, true 
      cout << ":" << std::setw(2) << std::setfill('0') << second_; 
      if(hour_ >= 12) {
        //pm
        cout << " p.m." << endl; 
      } else {
        cout << " a.m." << endl; 
      }
    } else{ 
      //false, false 
      if(hour_ >= 12) {
        //pm
        cout << " p.m." << endl; 
      } else {
        cout << " a.m." << endl; 
      }
    }
  } else {
    //military time
    cout << std::setw(2) << std::setfill('0') << hour_ << ":" << std::setw(2) << std::setfill('0') << minute_;
    if(displaySeconds) {
      cout << ":" << std::setw(2) << std::setfill('0') << second_ << endl; 
    } else {
      cout << endl; 
    }
  }

}