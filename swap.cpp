
#include <iostream>

// Not using namespace, so I don't pick up the bad habit
using std::cout;
using std::cin;
using std::endl;

template <typename T> // Assuming swapped items are same type
void swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
bool test(T* a, T* b){
    T valOne, valTwo;
    valOne = *a; valTwo = *b;

    swap(a,b);

    if(valOne == *b && valTwo == *a)
        return true;
    else
        return false;
}

template <typename T>
void testCustomVals(){
    T a,b;
    cout<< "Input first value to be swapped: "; cin>> a; cout<< endl;
    cout<< "Input second value to be swapped (same type as first): "; cin>> b; cout<< endl;

    cout<< "Current values are: a = "<<a<<", b = "<< b << endl;
    swap(&a,&b);
    cout<< "Values after swapping: a = "<<a<<", b = "<< b << endl;
}

int main(){

    // Tests will return 1 if passed, 0 if failed

    int a = 5; int b = 7;
    int *ptrA = &a; int *ptrB = &b;
    cout<< "Test 1 Results: " << test(ptrA,ptrB) << endl;

    float c = 5.1; float d = 7.2;
    float *ptrC = &c; float *ptrD = &d;
    cout<< "Test 2 Results: " << test(ptrC,ptrD) << endl;

    double e = -5.34; double f = 7.45;
    double *ptrE = &e; double *ptrF = &f;
    cout<< "Test 3 Results: " << test(ptrE,ptrF) << endl;

    char g = 'g'; char h = 'h';
    char *ptrG = &g; char *ptrH = &h;
    cout<< "Test 4 Results: " << test(ptrG, ptrH) << endl;

    bool i = true; bool j = false;
    bool *ptrI = &i; bool *ptrJ = &j;
    cout<< "Test 5 Results: " << test(ptrI, ptrJ) << endl;

    // testCustomVals<int>(); // Uncomment to perform own test

    return 0;
}