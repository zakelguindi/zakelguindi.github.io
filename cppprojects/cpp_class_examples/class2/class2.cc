//Copyright 2023 Zak Elguindi 
#include <iostream> //any code that uses cout or cin we use iostream 
using std::cout; 
using std::endl; 
using std::cin; 

int main() {
    double height; 
    cout << "How tall are you? \n  feet\r"; 
    cin >> height; 
    cout << "I got " << height << " feet" << endl; 
    return 0; 
}

/* int main() {  //need main function
    std::cout << "Hello World!" <<std::endl;  //use endl to skip to the next line in the buffer 
    std::cout << "What's up\n"; 
    int x, y, z; 
    x=5; 
    z=13;
    y = 10; 
    std::cout << "x = " << x << "\ny = " << y << "\nz = " << z << std::endl; 
    std::cout << "++x = " << ++x << std::endl; 
    int w = 4 * ++y; 
    std::cout <<"w = " << w << std::endl; 
    const double kNum = 15; //a constant variable (must start with k)- can't change its value after declaration 
    return 0; 
} */