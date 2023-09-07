//Copyright 2023 Zak Elguindi

#include"timeinterval.h"
#include<iostream>
#include<iomanip>
#include<string>
using std::string; 
using std::cout; 
using std::endl;

TimeInterval::TimeInterval() {                            
  SetStartTime(TimeOfDay(0,0,0)); 
  SetEndTime(TimeOfDay(0,0,0)); 
}

TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end) {
  //
  if(start.GetHour() >= end.GetHour()) {
    if(start.GetMinute() >= end.GetMinute()) {
      if(start.GetSecond() > end.GetSecond()) {
        //if start > end
        end_.SetHour(start.GetHour()); 
        end_.SetMinute(start.GetMinute()); 
        end_.SetSecond(start.GetSecond()); 

      }
    }
  } else {
    end_.SetHour(end.GetHour()); 
    end_.SetMinute(end.GetMinute()); 
    end_.SetSecond(end.GetSecond()); 
  }
  SetStartTime(start); 
  SetEndTime(end); 
}

TimeInterval::TimeInterval(const TimeOfDay& start, const int length, const string units)
 : start_(start), end_(start) {
 if(units == "hours" || units == "minutes" || units == "seconds") {
    //need to set end time to something 
    SetEndTime(length, units); 
  }
}

void TimeInterval::SetStartTime(const TimeOfDay& start) {
  //leave it unchanged
  if(start.GetHour() < end_.GetHour() || 
     (start.GetHour() == end_.GetHour() && start.GetMinute() < end_.GetMinute()) || 
    (start.GetHour() == end_.GetHour() && start.GetMinute() == end_.GetMinute() && start.GetSecond() <= end_.GetSecond())) {
      //it's good 
      start_.SetHour(start.GetHour()); 
      start_.SetMinute(start.GetMinute()); 
      start_.SetSecond(start.GetSecond()); 
    }
}

void TimeInterval::SetEndTime(const TimeOfDay& end) {
  //leave it unchanged 
  if(end.GetHour() > start_.GetHour() || 
      (end.GetHour() == start_.GetHour() && end.GetMinute() > start_.GetMinute()) ||
      (end.GetHour() == start_.GetHour() && end.GetMinute() == start_.GetMinute() && end.GetSecond() >= start_.GetSecond())) {
    end_.SetHour(end.GetHour()); 
    end_.SetMinute(end.GetMinute()); 
    end_.SetSecond(end.GetSecond());
  } else {
  }
}

void TimeInterval::SetEndTime(const int length, string units) {
  int endH = 0; 
  int endM = 0; 
  int endS = 0; 
  if(units == "seconds") {
    endH = length / 3600; 
    endM = (length % 3600) / 60; 
    endS = length % 60; 
  } else if(units == "minutes") {
    int newlength = length * 60; 
    endH = newlength / 3600; 
    endM = (newlength % 3600) / 60; 
    endS = newlength % 60;     
  } else if(units == "hours") {
    //int newlength = length * 3600; 
    endH = length ; 

  } else {
    SetEndTime(end_); 
    return; 
  }
 if(endS + start_.GetSecond() >= 60) {
    endM++; 
    endS -= 60; 
  }
  if(endM + start_.GetMinute() >= 60) {
    endH++; 
    endM -= 60; 
  }
 if((start_.GetHour() + endH) < 24 && (start_.GetMinute() + endM) < 60
      && (start_.GetSecond() + endS) < 60) {
        //time is valid 
        TimeOfDay end = TimeOfDay((start_.GetHour() + endH), (start_.GetMinute() + endM), 
                                  (start_.GetSecond() + endS));
        SetEndTime(end); 
      } else {
        //time is invalid 
        SetEndTime(end_); 
      }
}

void TimeInterval::Print(const bool& militaryTime, const bool& displaySeconds) {

  cout << "Start time: "; 
  start_.Print(militaryTime, displaySeconds); 
  cout << "End time: "; 
  end_.Print(militaryTime, displaySeconds); 
}

