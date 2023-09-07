//Copyright 2023 Zak Elguindi 

#include<iostream> 
using std::cout; 
using std::cin; 
using std::endl; 
#include<cmath> 
#include<iomanip>


int main() {

  char answer; 
  int num1 = 0; 
  int num2 = 0;
  int num3 = 0;
  char arth_operator;
  char rel_operator;
  double attempts = 0; 
  double correct = 0; 

  do {

    bool valid_arth = true; 
    bool valid_rel = true; 

    cin >> num1 >> arth_operator >> num2 >> rel_operator >> num3;  

    if(arth_operator != char(43) && arth_operator != char(45) && arth_operator != char(37) 
    && arth_operator != char(42) && arth_operator != char(47)) {
      if(rel_operator != char(60) && rel_operator != char(62)) {
        cout << "Unrecognized arithmetic operator " << arth_operator << endl; 
      } 
      else {
        cout << "Unrecognized arithmetic operator " << arth_operator; 
      }
      valid_arth = false; 
    } 
    if(rel_operator != char(60) && rel_operator != char(62)) { 
      cout << "Unrecognized relational operator " << rel_operator;
      valid_rel = false; 
    }
    //cout << valid_rel << " " << valid_arth << endl; 
    if((valid_rel == 1) && (valid_arth == 1)) {
      attempts++; 
      cout << num1 << " " << arth_operator << " " << num2 <<
      " " << rel_operator << " " << num3 << " - "; 
    }

    //addition 
    if(arth_operator == char(43)) {
      if(rel_operator == char(60)) {
        //less than 
        if((num1 + num2) < num3) {
          //if sum is less than 3, it's correct
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
      else if (rel_operator == char(62)) {
        //greater than 
        if((num1 + num2) > num3) {
          //if sum is greater than 3, it's correct 
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
    }
    //subtraction 
    else if(arth_operator == char(45)) {
      if(rel_operator == char(60)) {
        //less than 
        if((num1 - num2) < num3) {
          cout << "Correct";
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      } else if(rel_operator == char(62)) {
        //greater than
        if((num1 - num2) > num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
    }
    //multiplication
    else if(arth_operator == char(42)) {
      if(rel_operator == char(60)) {
        //less than 
        if((num1 * num2) < num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      } 
      else if(rel_operator == char(62)) {
        //greater than 
        if((num1 * num2) > num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
    }
    //division 
    else if(arth_operator == char(47)) {
      if(rel_operator == char(60)) {
        //less than 
        if((num1 / num2) < num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      } 
      else if(rel_operator == char(62)) {
        //greater than 
        if((num1 / num2) > num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect";
        }
      }
    }

    //mod operator 
    else if(arth_operator == char(37)) {
      if(rel_operator == char(60)) {
        //less than 
        if((num1 % num2) < num3) {
          cout << "Correct";
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
      else if(rel_operator == char(62)) {
        //greater than 
        if((num1 % num2) > num3) {
          cout << "Correct"; 
          correct++;
        } else {
          cout << "Incorrect"; 
        }
      }
    }
    cout << endl; 
    cin >> answer; 
  } 
  while(answer != 'q' && answer == 'c');

  float accuracy = correct/attempts * 100;

  if(attempts == 0) {
    accuracy = 0.00;
  }
  cout << correct << " of " << attempts << " = " << std::setiosflags( std::ios::showpoint | std::ios::fixed) << std::setprecision(2) << accuracy << "%" << endl;
  return 0; 
}
