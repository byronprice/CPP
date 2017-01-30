// multiply.cpp
//
// C tutorial
// Byron Price  2017/01/17
//
// Calculate the product of two numbers

#include <stdio.h>

int val1, val2, val3;

int product(int x, int y);

int main() {
    printf("Enter a number between 1 and 1000: ");
    scanf("%d",&val1);

    printf("Enter a second number: ");
    scanf("%d",&val2);

    val3 = product(val1,val2);

    printf("%d times %d = %d\n",val1,val2,val3);

    return 0;
}

int product(int x, int y) {
    return (x*y);
}