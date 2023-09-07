//Copyright 2023 Zak Elguindi 

#include"program2functions.h"
#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

//works 
bool LeapYear(int year) {
  if(year < 0) {
    return false; 
  }
  if((year % 4) == 0) {
    if((year % 100) == 0 && (year % 400) == 0) {
      return true; 
    }
    else if((year % 100) == 0) {
      return false; 
    }
    return true; 
  }
  return false; 
}

//works
int LastDayOfMonth(int month, int year) {
  if(month == 2 && year == 0) {
    return 0; 
  }
  else if(month > 12 || month < 0) {
    return 0; 
  }
  else if(month == 2) {
    if(LeapYear(year)) {
      return 29; 
    } 
    else {
      return 28; 
    }
  }
  else if(month == 1 || month == 3 || month == 5 || month == 7 
  || month == 8 || month == 10 || month == 12) {
    return 31;
  }
  else if(month == 4 || month == 6 || month == 9 || month == 11) {
    return 30; 
  }
  else {
    return 0; 
  }
}

//works
bool ValidDate(int month, int day, int year) {
  if(year < 0 || month < 0 || day < 0 || month > 12) {
    return false; 
  }
  else if(day > 0 && day <= LastDayOfMonth(month, year)) {
    return true; 
  }
  return false; 
}

//works
bool NextDate(int& month, int& day, int& year) {
  if(!ValidDate(month, day, year)) {
    return false;
  } 
  else if(day == LastDayOfMonth(month, year)) {
    day = 1; 
    if(month == 12) {
      month = 0; 
      year++; 
    }
    month++; 
  }
  else {
    day++; 
  }
  return true; 
}

//works
bool PreviousDate(int& month, int& day, int& year) {
  if(!ValidDate(month, day, year)) {
    return false; 
  }
  else if(day == 1) {
    if(month == 1) {
      year--; 
      month = 13; 
    }
    month--; 
    day = LastDayOfMonth(month, year); 
  }
  else {
    day--; 
  }
  return true;
}