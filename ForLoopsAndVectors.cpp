// ForLoopsAndVectors.cpp
//
// created by Byron Price, 2017/01/09

#include <iostream>
#include <stdio.h> // for printf
#include <math.h> // for sqrt
#include <cstdlib> // for rand()
#include <time.h> // to initialize rand()
#include <fstream> // read/write to .txt files

/* example printf usage
    printf("sqrt(%f) = %f\n",param,result);

    see http://www.cplusplus.com/reference/cmath/sqrt/
    for info on different cpp libraries
*/

// declare a function
int mult (int x, int y);

// declare and define a structure
struct multiplyValues {
    int mynumber[2],random,z,randMax,*mypointer;
};

int main() {
    // how to create an example of a "multiplyValues" structure
    struct multiplyValues Data;

    srand(time(NULL)); // initialize random seed

    // declare variables
    // int a, b, c, d;
    // char letter;
    // float myfloat, yourfloat;
    // bool truefalse;  // truefalse would be 0 (false) or 1 (true)

    // example for and while loops
    for (int ii= 0; ii<2; ii++) {
        std::cout << "Please enter a number: ";
        std::cin >> Data.mynumber[ii];
        std::cin.ignore();
    }

    Data.z = mult(Data.mynumber[0],Data.mynumber[1]);
    /*
    for (int ii = 0; ii<10; ii++) {
        mynumber = mynumber+1;
        std::cout << ii << std::endl;
     }
     */
     /*
     int x = 0;

     while (x < 10) {
        std::cout << x << std::endl;
        x++; // update x, or you could do, x = x+1;
     }

     do {

     } while ( condition ) ; // while "condition" is TRUE
     */
   // std::cout << "Your number plus 10 is " << mynumber << ".\n";

   // another way to output text to the terminal
   printf("%i times %i equals %i\n",Data.mynumber[0],Data.mynumber[1],Data.z);

   // initialize a random number
   Data.randMax = 100;
   Data.random = rand()%Data.randMax;

   printf("Random number generated is %i\n",Data.random);

   // assigning and dereferencing pointers
   Data.mypointer = &Data.random;
   std::cout << "Pointer address: " << Data.mypointer << std::endl;
   std::cout << "Value at that address: " << *Data.mypointer << std::endl;

   // declare a 10-by-10 float array, and fill its entries
   // also write the data to a .txt file
   int arraySize = 10;
   float randArray[arraySize][arraySize];
   std::ofstream myfile ("example.txt");
   for (int ii=0; ii<arraySize; ii++) {
      for (int jj=0; jj<arraySize; jj++) {
            randArray[ii][jj] = rand()%Data.randMax;
            myfile << ii << " ";
            myfile << jj << " ";
            myfile << randArray[ii][jj] << "\n";
      }
    }
    float myfloat;
    unsigned char mybinary[] = {0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    memcpy(&myfloat,&mybinary,sizeof(myfloat));
    std::cout << "Float value: " << myfloat << std::endl;
}

// define a function
int mult (int x, int y) {
    return x*y;
}

/*
#include <iostream>

using namespace std;

struct xampl {
  int x;
};

int main()
{
  xampl structure;
  xampl *ptr;

  structure.x = 12;
  ptr = &structure; // Yes, you need the & when dealing with structures
                    //  and using pointers to them
  cout<< ptr->x;    // The -> acts somewhat like the * when used with pointers
                    //  It says, get whatever is at that memory address
                    //  Not "get what that memory address is"
  cin.get();
}
*/