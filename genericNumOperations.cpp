
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class nums{
    private:

    T num1, num2, result;

    public:

    nums(){ // Default constructor
        num1 = 0; num2 = 0; result = 0;
    }

    nums(T number1, T number2){ // Non-default Constructor
        num1 = number1; num2 = number2; result = 0;
    }

    // GETTERS ----------
    T getResult(){return result;}
    T getNum1(){return num1;}
    T getNum2(){return num2;}

    // SETTERS ----------
    void setNum1(T num){num1 = num;}
    void setNum2(T num){num2 = num;}

    // OPERATIONS ----------
    void add(){
        result = num1 + num2;
    }

    void subtract(){
        result = num1 - num2;
    }

    void multiply(){
        result = num1 * num2;
    }

    void divide(){
        result = num1 / num2;
    }
};

int main(){

    // Other test cases
//    float testNum1; float testNum2;
//    double testNum1; double testNum2;


    int testNum1; int testNum2; // Change types for different test cases

    cout<< "Input num1: "; cin>> testNum1; cout<< endl;
    cout<< "Input num2 (same type as num1): "; cin>> testNum2; cout<< endl;


    nums pair(testNum1,testNum2);
    cout<< "num1 is: " << pair.getNum1() << endl << "num2 is: "<< pair.getNum2() << endl;


    pair.add();
    cout<< "Addition: " << pair.getResult() << endl;

    pair.subtract();
    cout<< "Subtraction: " << pair.getResult() << endl;

    pair.multiply();
    cout<< "Multiplication: " << pair.getResult() << endl;

    pair.divide();
    cout<< "Division: " << pair.getResult() << endl;

    // Testing setters
    cout << "Testing Setters with 4, 5:" << endl;
    pair.setNum1(4); pair.setNum2(5);
    cout<< "Nums after using setter: "<< pair.getNum1() << ","<< pair.getNum2();
}