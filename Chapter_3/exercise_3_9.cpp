#include "../std_lib_facilities.h"

/*
    Write a program that converts spelled-out numbers such as "zero" and "two"
    into 0 and 2. When the user inputs a number, the program should output the
    corresponding digit. For values 0, 1, 2, 3, and 4. Write NaN otherwise.
*/

int main() {
    string input;
    cout << "Enter a spelled-out number to be converted to its corresponding digit: ";
    cin >> input;

    if (input == "zero") {
        cout << 0;
    } else if (input == "one") {
        cout << 1;
    } else if (input == "two") {
        cout << 2;
    } else if (input == "three") {
        cout << 3;
    } else if (input == "four") {
        cout << 4;
    } else {
        cout << "Not a number!";
    }

    return 0;
}