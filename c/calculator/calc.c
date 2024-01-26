#include <stdio.h>

/**
 * to compile: 
 * clang -o calc calc.c
 * */

// all functions must be declared up here: 
int add(int num1, int num2); 
int subtract(int a, int b); 
int multiply(int a, int b); 
int divide(int a, int b); 


int main() {
    int num1, num2; 
    char operator; 


    /**
     * for scanf, different types require different ways of calling
     * %d = int, %f = float, %c = char, %s = string
     * */

    /**
     * for calculator: need operator and number 
     * create switch statement after getting operator and number 
     * create methods for add, subtract, mult, and divide
     * */


    printf("Enter your first number"); 
    scanf("%d", &num1); 
    printf("Enter your second number"); 
    scanf("%d", &num2); 
    printf("Enter your operator"); 
    scanf(" %c", &operator); //need to have the space before the %c. 


    

    switch(operator) {
        case '+':
            printf("Result: %d\n", add(num1, num2)); 
            break; 
        case '-':
            printf("Result: %d\n", subtract(num1, num2)); 
            break;
        case '*':
            printf("Result: %d\n", multiply(num1, num2)); 
            break;
        case '/':
            if(num2 != 0) {
                printf("Result: %d\n", divide(num1, num2)); 
            } else {
                printf("Divide by 0 error"); 
            }
            break; 
        default:
            printf("Invalid operator");
            break; 
    }


    return 0; 

}

int add(int num1, int num2) {
    return num1 + num2; 
}

int subtract(int a, int b) {
    return a-b; 
}

int multiply(int a, int b) {
    return a*b; 
}

int divide(int a, int b) {
    return a/b; 
}