//Copyright 2023 Zak Elguindi
//Write a function named NumDigits that takes an integer parameter and returns the number of digits in the integer. 

#ifndef _PROBLEM3FUNCTIONS_H_
#define _PROBLEM3FUNCTIONS_H_ 

int NumDigits(int); 
/*
Write a function named FindAndReplace that replaces digits within an integer
variable.
The function will take an integer variable to search, a positive integer to find,
and a positive integer to replace as arguments. The function should find all
occurrences of the find integer within the integer variable and replace them with
replace integer, moving from right to left.
Preconditions: the second and third arguments should be positive integers,
and the second argument should contain at least as many digits
as the third argument. If the preconditions are not met, the
function should return false and leave the first integer unchanged 
*/

bool FindAndReplace(int& x, int find, int replace); 


#endif