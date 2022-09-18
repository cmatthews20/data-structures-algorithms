
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printMaxVal(int *arr, int numVals){
    int maxVal = arr[0];

    for(int i = 1; i < (numVals); i++){
        if(maxVal < arr[i]){
            maxVal = arr[i];
        }
    }

    cout<< maxVal;
}


int main() { // Test script - run program and input test values

    int numVals; cout<< "Input the number of data values: "; cin>> numVals; // Ask for size of array

    int *vals = new int[numVals]; // Make array

    int val; // declare variable for inputted values

    // Iterate and fill array
    for(int i = 0; i < numVals; i++){
        cout<< "Input value " << i + 1 << ": "; cin>> val;
        vals[i] = val;
    }

    printMaxVal(vals, numVals); // Call function to print max value from array

    delete[] vals; // Prevent memory leak

    return 0;
}
