// fgets_example.cpp
//
// Byron Price 2017/01/17
//
// Example of proper fgets usage
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[256];

    printf("Enter your name and then press <Enter>: ");
    fgets(buffer,sizeof(buffer),stdin);

    printf("\nYour name has %lu characters and spaces.\n",strlen(buffer)-1);

    return 0;
}