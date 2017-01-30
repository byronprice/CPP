// UserInterface.cpp
//
// created by Byron Price, 2017/01/09

#include <iostream>
#include <stdio.h> // for printf
#include <math.h> // for sqrt

/* example printf usage
    printf("sqrt(%f) = %f\n",param,result);

    see http://www.cplusplus.com/reference/cmath/sqrt/
    for info on different cpp libraries
*/

int main()
{
    int mynumber, comparison;
    float numsqrt;

    // declare variables
    // int a, b, c, d;
    // char letter;
    // float myfloat, yourfloat;
    // bool truefalse;  // truefalse would be 0 (false) or 1 (true)
    std::cout << "Please enter a number: ";
    std::cin >> mynumber;
    std::cin.ignore();
    numsqrt = sqrt(mynumber);
    std::cout << "Square root of your number: " << numsqrt << "\n";
    //std::cin.get();

    comparison = 50;
    if (mynumber > comparison) {
        std::cout << "Your number is greater than " << comparison << ".\n";
    }
    else if (mynumber == comparison) {
        std::cout << "Your number is equal to " << comparison << ".\n";
    }
    else {
        std::cout << "Your number is less than " << comparison << ".\n";
    }
    return 0;

    // cpp boolean operators are OR || , AND && , and NOT !
}