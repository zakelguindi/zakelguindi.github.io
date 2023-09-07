//Copyright 2023 Zak Elguindi
//example structure type 
#include<iostream> 
using std::cin; 
using std::cout; 
using std::endl; 

struct Point {
  int x;
  int y; 
}; 

int main() {
  Point myPoint; 
  cout << "Enter the x and y coordinates of a point "; 
  cin >> myPoint.x >> myPoint.y; 
  cout << "The point is (" << myPoint.x << ", " <<myPoint.y << ")" << endl; 
  Point somePoints[5]; 
  cout << "Enter the coordinates for five points "; 
  for(int i=0; i<5; i++) {
    cin >> somePoints[i].x >> somePoints[i].y; 
  }
  for(int i=0; i<5; i++) {
    cout << "{" << somePoints[i].x << ", " << somePoints[i].y << ")" << endl; 
  }
  Point * pointpointer = &myPoint; 
  cout << "Access a member through a pointer, method 1: " << (*pointpointer).x
    << "\nAccess a member through a pointer, method 2: " << pointpointer->y 
    << endl; //they do the same thing 
  return 0; 
}