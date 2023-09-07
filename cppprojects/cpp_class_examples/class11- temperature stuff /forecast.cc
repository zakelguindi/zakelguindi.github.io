//Copyright 2023 Zak Elguindi 
//Implement functionality of forecast.h "forecast" class 
#include"forecast.h" //don't technically need to include temp.h bc it's already included in forecast.h 
#include"temperature.h"
#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

Forecast::Forecast(const Temperature& low, const Temperature& high, double rain) : low_(low), high_(high) { //can set defaults in args 
  chance_of_rain_ = 0; 
  SetChanceOfRain(rain); 
}

void Forecast::SetChanceOfRain(double rain) {
  if ( rain >= 0 && rain <= 100) {
    chance_of_rain_ = rain; 
  }
}

void Forecast::SetLow(const Temperature& low) {
  if(low < high_) {
    // should make functionality comparing temps in temp class
    low_.SetValue(low.GetValue());
    low_.SetUnit(low.GetUnits()); 
  }
}

void Forecast::SetHigh(const Temperature& high) {
  if(low_ < high) {
    high_.SetValue(high.GetValue()); 
    high_.SetUnit(high.GetUnits());
  }
}

void Forecast::Print() const {
  cout << "Forecast low: "; //low_.value_; can't directly access the temperature object's private data member, could call get functions
  low_.Print();  
  cout << "Forecast high: "; 
  high_.Print(); 
  cout << "Chance of precipitation: " << chance_of_rain_ << "%" << endl; 
}