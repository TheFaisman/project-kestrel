#include "../std_lib_facilities.h" 

/*
    Write a program that takes an operation followed by two operands and outputs the result.
    For example:
        + 100 3.5
*/

int main() {
    string operand = " ";
    double input[2];
    cout << "Enter an operand (+, -, *, /) followed by two numbers: ";
    cin >> operand >> input[0] >> input[1];

    if (operand == "+") {
        cout << input[0] + input[1];
    } else if (operand == "-") {
        cout << input[0] - input[1];
    } else if (operand == "*") {
        cout << input[0] * input[1];
    } else if (operand == "/") {
        cout << input[0] / input[1];
    }
     
    return 0;
}