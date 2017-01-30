// variables.cpp
//
// created 2017/01/23
//  Byron Price
// C tutorial

// variable types
//  character  char  -128 to 127
// short integer  short -32767 to 32767
// integer   int  -2147483647 to -2147438647
// long integer  long  same as above
// long long integer  long long  -9e18 to 9e18
// unsigned character unsigned char 0 to 255
// unsigned short
// unsigned int
// unsigned long
// unsigned long long
// float   1.2e-38 to 3.4e38  ... 7 digit precision
// double  2.2e-308 to 1.8e308  ... 19 digit precision

//  use sizeof(char) or sizeof(int) or sizeof(float) to determine number of bytes for a given variable type
// typedef int integer;  ... this means the compiler recognizes integer as it does int, e.g. rather than
// int count  you could write  integer count

// literal constants versus symbolic constants ... constants do not change value during program execution
//  LITERAL
//    int count = 20;  float tax_rate = 0.25;
//  SYMBOLIC ... no semi-colon necessary
//    #define PI 3.14159
//    const int count = 100;
//    const float pi = 3.14159;

#include <stdio.h>

const double kilos_per_lb = 0.453592;
const double meters_per_inch = 0.0254;

float weight_in_lbs, weight_in_kilos, height_in_inches, height_in_meters,feet_height, inches_height;

int main() {
    printf("Enter your weight in pounds: ");
    scanf("%f",&weight_in_lbs);
    printf("Enter your height in feet and inches (e.g. 6 4): ");
    scanf("%f %f",&feet_height,&inches_height);

    weight_in_kilos = weight_in_lbs*kilos_per_lb;
    height_in_inches = feet_height*12+inches_height;
    height_in_meters = height_in_inches*meters_per_inch;

    printf("\nYour weight in kilograms: %3.2f",weight_in_kilos);
    printf("\nYour height in meters: %3.2f\n",height_in_meters);

    return 0;
}