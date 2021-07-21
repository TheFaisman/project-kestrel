#include "../std_lib_facilities.h"

/*
    Write a program that performs as a very simple calculator. Your calculator should be able
    to handle the four basic math operations - add, subtract, multiply, and divide - on two
    input values. Your program should prompt the user to enter three arguments. Two double
    values and a character to represent an operation.

    For eg. The input '53.1 34.3 +' should output "The sum of 43.1 and 34.3 is 87.4."
*/

int main() {
    cout << endl;
    cout << "Simple Calculator 1.0 - Est. 2021\n";
    cout << "Supported operations include +, -, /, *.\n";
    cout << "Input example: '2 3 +'\n" << endl;
    cout << "Input: ";

    double input_1, input_2, result = 0;
    char operation = ' ';

    cin >> input_1 >> input_2 >> operation;

    switch (operation)
    {
    case '+':
        result = input_1 + input_2;
        break;
    case '-':
        result = input_1 - input_2;
        break;
    case '/':
        result = input_1 / input_2;
        break;
    case '*':
        result = input_1 * input_2;
        break;
    default:
        cerr << "Operation undefined. I do not support the '" << operation << "' operator.\n";
        simple_error("Operator input error.");
        break;
    }

    cout << "The output is " << result << ".\n";

    return 0;
}