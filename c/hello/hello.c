#include <stdio.h>
/**
 * to compile: 
 * clang -o hello hello.c
 * ./hello
 * */

int main() {
    printf("Hello world"); 
    int num; 
    float floatNum; 
    //reading an int - use %d 
    printf("Enter an integer: "); 
    scanf("%d", &num); 
    printf("You entered: %d\n", num); 

    //reading a float- use %f
    printf("Enter a float: "); 
    scanf("%f", &floatNum); 
    printf("You entered: %f\n", floatNum);

    return 0; 
}