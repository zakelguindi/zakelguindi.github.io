// Copyright 2023 Zak Elguindi 
//Decisions, Case, Loops 

#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

int main() {
  char language; 

  // --------for loops but as a while loop ------ 
  int i = 1; 
  while(i<=10 ) {
    cout << i << " "; 
    ++i; 
  }
  cout << endl; 

  // ------ for loops -------
  for(int j=1; j<=10; ++j ) 
    cout << j << " "; 
  cout << endl; 

  //can have multiple variables in loop 
  for(int j=1, k=2; j <= 10; ++j, ++k)
    cout << j << " and k = " << k << "\n"; 
  cout << endl; 

  return 0; 
}


/* ------ do-while example -------

  do {
    cout << "(E)nglish, (S)panish, (F)rench "; 
    cin >> language; 
  } while ( language != 'E' && language != 'F' && language != 'S' && language != 'e');
*/ 


  /*  --------while loop example --------
  cout << "(E)nglish, (S)panish, (F)rench "; 
  cin >> language; 

  while ( language != 'E' && language != 'F' && language != 'S' && language != 'e'
  && language != 'f' && language != 's') {
    cout << "Try again"; 
    cin >> language; 
  }
  */

/* ----switch-case example ------

  //switch executes all commands from that point forward until you tell it to stop 
  switch ( language ) {
    case 'E': 
    case 'e': //does same as uppercase E 
      cout << "Hello\n";
      break; 
    case 'S':
      cout << "Hola\n"; 
      break; 
    case 'F':
      cout << "Salut\n"; 
      break;
    default:
      cout << "Invalid entry\n"; 
  }
  return 0; 
}
*/ 
/*  -----grade calculator example -------


int main() {
  double grade; 
  cout << "Enter your numeric grade: "; 
  cin >> grade; 
  if( grade <= 59.5 ) 
    cout << "You didn't pass\n"; 
  else
    cout << "You passed\n"; 
  //logical expression ? true side : false side
  cout << "You " << (grade >= 59.5 ? "passed" : "didn't pass") << endl; 

  int tickets; 
  cout << "How many tickets would you like?"; 
  cin >> tickets; 
  cout << "You purchased " << tickets << "ticket" << (tickets == 1  ? "" : "s");

  return 0; 
}
*/