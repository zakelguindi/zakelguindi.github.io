//Copyright 2023 Zak Elguindi 

#include"problem2functions.h"
#include<iostream>
#include<cmath>
using std::cout; 
using std::cin; 
using std::endl; 

double Distance(double x1, double y1, double x2, double y2) {
  double distance = 0.0; 
  distance = pow(((pow((x2-x1), 2.0)) + (pow((y2-y1), 2.0))), 0.5);
  return distance;
}

int OnCircle(double x1, double y1, double radius, double x2, double y2) {
  /**
   * x1 and y1 are center circle 
   * x2 and y2 are new point 
   * if x2y2 is inside circle, return -1 
   * if x2y2 is outside circle, return 1 
   * if it's on circle, return 0
   * find slope of circle/edgepoints
   * x^2 + y^2 = r^2
   * */
  double relativex = x2-x1; 
  double relativey = y2-y1; 
  double relativeslope = (pow(relativex, 2.0)) + (pow(relativey, 2.0));
  double r2 = pow(radius, 2.0); 
  if(relativeslope < r2) {
    return -1; 
  }
  else if(relativeslope > r2) {
    return 1; 
  }
  else if(relativeslope == r2) {
    return 0; 
  }
}

bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
  /**
   * find the slopes of point 1 to 2, and 2 to 3, if they match, return true
   * */
  double slope1 = (y2-y1) / (x2-x1); 
  double slope2 = (y3-y2) / (x3-x2); 

  if(slope1 == slope2) {
    return true; 
  }
  else {
    return false; 
  }
}