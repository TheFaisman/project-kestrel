#include "../std_lib_facilities.h"
// Mile to kilometer converter
// There are 1.609 km in a mile
const double km_per_mile = 1.609;

int main() {
    cout << "Enter the number of miles to be converted to km: ";
    double miles = 0;
    cin >> miles;

    double km = miles*km_per_mile;
    cout << "Number of km: " << km;
    return 0;
}