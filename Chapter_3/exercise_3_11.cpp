#include "../std_lib_facilities.h"

/*
    Write a program that prompts the user to enter some number of pennies, nickels, dimes,
    quarters, and dollars.
*/

int main() {
    int pennies, nickels, dimes, quarters, loonies, toonies = 0;
    
    const double penny_val = 0.01;
    const double nickel_val = 0.05;
    const double dime_val = 0.10;
    const double quarter_val = 0.25;
    const double loonie_val = 1.00;
    const double toonie_val = 2.00;

    double dollar_sum = 0;

    cout << "Enter the number of pennies: ";
    cin >> pennies;
    cout << "Enter the number of nickels: ";
    cin >> nickels;
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    cout << "Enter the number of quarters: ";
    cin >> quarters;
    cout << "Enter the number of loonies: ";
    cin >> loonies;
    cout << "Enter the number of toonies: ";
    cin >> toonies;

    dollar_sum = (pennies * penny_val)
        + (nickels * nickel_val)
        + (dimes * dime_val)
        + (quarters * quarter_val)
        + (loonies * loonie_val) 
        + (toonies * toonie_val);
    
    cout << "Your total is: $" << dollar_sum;
}