//Copyright 2023 Zak Elguindi 

#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 
#include"program2functions.h"

int main() {
  int month1, day1, year1, month2, day2, year2; 
  char slash1, slash2, slash3, slash4; 

  cin >> month1 >> slash1 >> day1 >> slash2 >> year1 >> month2 >>
  slash3 >> day2 >> slash4 >> year2; 

  if(!ValidDate(month1, day1, year1)) {
    cout << month1 << slash1 << day1 << slash2 << year1 << " is not a valid date" << endl; 
  } 
  if(!ValidDate(month2, day2, year2)) {
    cout << month2 << slash3 << day2 << slash4 << year2 << " is not a valid date" << endl; 
  }
  if(!ValidDate(month1, day1, year1) || !ValidDate(month2, day2, year2)) {
    return 0; 
  }
  else {
    int totalDays = 0; 
    int m1 = month1; 
    int d1 = day1; 
    int y1 = year1; 
    //date 2 > date 1
    if((year2 > y1) || ((year2 == y1) && (month2 > m1)) || ((year2 == y1) && (month2 == m1) && (day2 > d1 ))) {
      while((year2 != year1) || (month2 != month1) || (day2 != day1)) {
        NextDate(month1, day1, year1); 
        // cout << month1 << slash1<< day1 << slash2 << year1 << endl; 
        totalDays++; 
      }
      cout << m1 << slash1 << d1 << slash2 << y1 << " is " << totalDays << " days before " 
      << month2 << slash3 << day2 << slash4 << year2 << endl; 
    }
    else if((year2 < year1) || ((year2 == year1) && (month2 < month1)) || (year2 == year1 && month2 == month1 && day2 < day1)) {
      // cout << "Here" << endl; 
      while((year2 != year1) || (month2 != month1) || (day2 != day1)) {
        // cout << "here " << endl; 
        PreviousDate(month1, day1, year1); 
        totalDays++; 
      }
      cout << m1 << slash1 << d1 << slash2 << y1 << " is " << totalDays << " days after " 
      << month2 << slash3 << day2 << slash4 << year2 << endl; 
    }
    else if(totalDays == 0) {
      cout << m1 << slash1 << d1 << slash2 << y1 << " is " << totalDays << " days before " 
      << month2 << slash3 << day2 << slash4 << year2 << endl; 
    }
  }
}