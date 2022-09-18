
#include <iostream>

template<typename T>
void natural(T num){ // Q1. Prints all natural numbers up to, and including, the provided limit
    if(num == 0){
        return;
    }else{
        natural(num-1);
        std::cout<<num<<", ";
    }
}

template<typename T>
T gcd(T a, T b){ // Q2. Computes GCD of two numbers
    if(b==0) {
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main() { // Test script
    std::cout << "The first 50 natural numbers are: ";
    natural(50);
    std::cout<<std::endl<<std::endl;

    std::cout<< "GCD of 10, 50 is: " << gcd(10,50)<<std::endl;
    std::cout<< "GCD of 22, 11 is: " << gcd(22,11)<<std::endl;
    std::cout<< "GCD of 64, 62 is: " << gcd(64,62)<<std::endl;
    std::cout<< "GCD of 1000, 1050 is: " << gcd(1000,1050)<<std::endl;
    std::cout<< "GCD of 2050, 2020 is: " << gcd(2050,2020)<<std::endl;
    std::cout<< "GCD of 19, 7 is: " << gcd(19,7)<<std::endl;
    return 0;
}
