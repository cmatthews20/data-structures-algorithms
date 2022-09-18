// Works for multi-digit numbers and exponents

#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

bool isDigit(char c){return(c>='0'&&c<='9');} // Check if char is a digit

bool isOperator(char c){return(c=='^'||c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')');} // Checks if operator

int getPrecedence(char c){ // Returns precedence of operator
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(':
        case ')': return 4;
        default: return -1;
    }
}

int operate(int val1, int val2, char op){ // Completes the given operation and returns the appropriate result
    if(op=='+') return val1+val2;
    if(op=='-') return val1-val2;
    if(op=='*') return val1*val2;
    if(op=='^') return pow(val1,val2);
    return val1/val2;
}

int evaluate(string s){ // Parses through string. Uses stack to evaluate string in several steps
    stack<int> values;
    stack<char> operands;

    int val = 0; int position = 0;

    while(position < s.length()){
        char spot = s[position];

        if(isDigit(spot)){
            val = (val*10)+ (int)(spot - '0');
        }
        else if(isOperator(spot)){
            if(spot == '('){
                operands.push(spot);
                val = 0;
            }
            else if(values.empty()){
                values.push(val);
                operands.push(spot);
                val = 0;
            }
            else if(spot==')'){
                values.push(val);
                while(operands.top() != '('){
                    spot = operands.top();
                    operands.pop();
                    val = values.top();
                    values.pop();
                    int prev = values.top();
                    values.pop();
                    val = operate(prev,val,spot);
                }
                operands.pop();
                values.pop();
            }
            else{
                char prev = operands.top();
                if(getPrecedence(spot) > getPrecedence(prev)){
                    values.push(val);
                    operands.push(spot);
                    val = 0;
                }
                else{
                    int prevval = values.top();
                    values.pop();
                    int prevop = operands.top();
                    operands.pop();
                    prevval = operate(prevval,val,prevop);
                    values.push(prevval);
                    operands.push(spot);
                    val = 0;


                }
            }
        }
        position++;
    }
    while(!operands.empty()){
        int prev = values.top();
        values.pop();
        char spot = operands.top();
        operands.pop();
        val = operate(prev,val,spot);
    }
    return val;
}

int main(){ // Main function for testing

    cout<< "Test:" << evaluate("3+4+5")<<endl; // 12
    cout<< "Test:" << evaluate("(3+4+5)")<<endl; // 12
    cout<< "Test:" << evaluate("3+4*5")<<endl; // 23
    cout<< "Test:" << evaluate("3*4+5")<<endl; // 17
    cout<< "Test:" << evaluate("-1*7")<<endl; // -7
    cout<< "Test:" << evaluate("3+2^3")<<endl; // 11

    string expression;
    cout<< "\nEnter your own expression: ";
    cin>>expression;
    cout<< "\nResult: " << evaluate(expression);

    return 0;
}