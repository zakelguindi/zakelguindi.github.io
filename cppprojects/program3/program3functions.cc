//Copyright 2023 Zak Elguindi 

#include"program3functions.h"
#include<iostream>
using std::cin; 
using std::cout; 
using std::endl;


//works 
bool Check(char c, int counter[], int size) {
  for(int i=0; i<size; i++) {
    int asciiValue = 97 + i; 
    if(c == char(asciiValue) || c == char(asciiValue - 32)) {
      counter[i]++;  
      return true; 
    }
  }
  return false; 
}

//works
void Sort(int counter[], char alphabet[], int size) {
  for(int place = 1; place < size; place++) {
    while(counter[place] > counter[place-1] && place > 0) {
      int temp = counter[place]; 
      counter[place] = counter[place-1]; 
      counter[place-1] = temp; 

      char c = alphabet[place]; 
      alphabet[place] = alphabet[place-1]; 
      alphabet[place-1] = c; 
      place--; 
    }
  }
}

//works
void TestPrint(int counter[], int size) {
  for(int i=0; i<size; i++) 
    cout << counter[i] << " "; 
  cout << endl; 
}

//works
void Print(int counter[], char alphabet[], int size) {
  for(int i=0; i<size; i++) {
    cout << alphabet[i] << ": " << counter[i] << endl; 
  }
}

//works- just do stuff for commas and display 
void SearchHighest(int counter[], char alphabet[], int size) {
  int nums = 1; 
  for(int i=0; i<size; i++) {
    if(counter[i+1] < counter[i]) {
      i = size; 
    } else {
      nums++; 
    }
  }
  int highest[nums]; 
  for(int i=0; i<nums;i++) {
    highest[i] = counter[i]; 
  }
  if(nums == 1) {
    cout << "Highest frequency character (appeared " << highest[0] << " times in the file):";
  } else {
    cout << "Highest frequency characters (appeared " << highest[0] << " times in the file):";
  }
   
  for(int i=0; i<nums; i++) {
    if(nums <= 1) {
      cout << " " << alphabet[i]; 
    } else if( nums == 2) {
      cout << " " << alphabet[i] << " and " << alphabet[i+1]; 
      i++; 
    } else {
      if(i == nums - 1) {
        cout << " and " << alphabet[i]; 
      } else {
        cout << alphabet[i] << ","; 
      }
    }
  }
  cout << endl;
}

//works just need to format it
void SearchLowest(int counter[], char alphabet[], int size) {
  int nums = 1; 
  for(int i=size-1; i>=0; i--) {
    if(counter[i] < counter[i-1]) {
      i = -1; 
    } else {
      nums++; 
    }
  }
  int lowest[nums]; 
  for(int i=0; i<nums; i++) {
    lowest[i] = counter[size-nums]; 
  }
  if(nums == 1) {
    if(lowest[0] == 1) {
      cout << "Lowest frequency character (appeared " << lowest[0] << " time in the file):"; 
    } else {
      cout << "Lowest frequency character (appeared " << lowest[0] << " times in the file):"; 
    }
  } else {
    if(lowest[0] == 1) {
      cout << "Lowest frequency characters (appeared " << lowest[0] << " time in the file):"; 
    } else {
      cout << "Lowest frequency characters (appeared " << lowest[0] << " times in the file):"; 
    }
  }

  for(int i=(size-nums); i<size; i++) {
    if(nums <= 1) {
      cout << " " << alphabet[i]; 
    } else if(nums == 2) {
      cout << " " << alphabet[i] << " and " <<alphabet[i+1]; 
    } else {
      if(i == size-1) {
        cout << " and " << alphabet[i]; 
      } else {
        cout << " " << alphabet[i] << ",";
      }
    }
  }
  cout << endl;
}

void Chart(int counter[], int originalCounter[], char alphabet[], int size) {
  const int x = size+1; //26
  const int y = counter[0]+1; //6


  for(int i=0; i<y; i++) {
    for(int j=0; j<x; j++) {
      if(i == y-1) {
        //bottom line with alphabet 
        if(j == 0 ) {
          cout << ' '; 
          if(y > 10) {
            cout << ' '; 
          }
        } else {
          cout << alphabet[j-1];
        }
      } else if(j == 0) {
        //y axis 
        if(y > 10) { 
          if(i >= y-10) {
            cout << ' ' << y - i - 1; 
          } else {
            cout << y - i - 1; 
          }
        } else {
          cout << y - i - 1; 
        }
      } else {
        int chartVal = y - i - 1; 
        // cout << "chart val: " << chartVal; 
        if(originalCounter[j-1] >= chartVal) {
          cout << '*'; 
        } else {
          cout << ' '; 
        }
      }
      if(j < x-1) {
        cout << ' '; 
      } 
    }
    cout << endl; 
  }
}
