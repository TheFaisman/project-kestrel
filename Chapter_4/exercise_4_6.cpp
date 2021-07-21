#include "../std_lib_facilities.h"
/*
    Make a vector holding the ten string values "zero", "one", ... , "nine".
    Use that in a program that converts a digit to its corresponding spelled-out value.
    Have the program use the same input loop, convert spelled out numbers into
    their digit form.
*/

int main() {
    vector<string> int_strings{"zero", "one", "two", "three", "four", 
                                "five", "six", "seven", "eight", "nine"};

    cout << "Enter a digit [0-9] to receive its spelled-out equivalent: ";
    int input_digit;
    while (cin >> input_digit) {
        if (input_digit < 0 || input_digit > 9) {
            simple_error("Invalid digit.");
        }
        cout << "The spelled-out digit is " << int_strings[input_digit] << ".\n";
    }
    return 0;
}