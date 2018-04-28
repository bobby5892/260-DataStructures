#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    // Unsorted Array
   const int arraySize = 50;
   int* data;
   data = new int[arraySize];
   // create array
   for(int i=0; i< arraySize; i++){
        *(data+i) = rand();
   }
   int numberOfAccess = 0;
   int numberOfSwaps = 0;
    // insertion sort
    for(int i=0; i<arraySize; i++){
        for(int j=0; j<arraySize; j++){
            if( *(data+i) < *(data+j) ){
                std::swap(data[i],data[j]);
                numberOfSwaps++;

            }
            numberOfAccess++;
        }
    }

    // display array
    for(int i=0; i<arraySize; i++){
        std::cout << "Line: " << i << " " << *(data+i) << std::endl;
    }
    std::cout << "Number of Swaps:" << numberOfSwaps << " Number of Accesses:" << numberOfAccess << std::endl;
    return 0;
}
