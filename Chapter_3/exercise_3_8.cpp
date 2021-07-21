#include "../std_lib_facilities.h"

/*
    Write a program to test an integer value to determine if it is odd or even.
*/

int main() {
    cout << "Input a number to determine if it's odd or even: ";
    int input;
    cin >> input;

    if ((input % 2) == 1) {
        cout << "This number is odd.";
    } else if ((input % 2) == 0) {
        cout << "This number is even.";
    }
    return 0;
}