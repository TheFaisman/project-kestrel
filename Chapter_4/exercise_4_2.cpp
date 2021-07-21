#include "../std_lib_facilities.h"

/*
    Take in a set of temperatures, then compute the mean and median
*/

int main() {
    cout << "Enter a sequence of temperatures, terminated by '|': ";
    vector<double> temps;
    for (double temp; cin >> temp;) {
        temps.push_back(temp);
    }
    sort(temps);

    // Compute mean temperature
    double sum = 0;
    for (double temp : temps) {
        sum += temp;
    }
    double mean = sum / temps.size();
    cout << "The average temperature is " << mean << ".\n";

    // Compute the median
    // If the size is odd, take the middle value
    // If the size is even, take the average of the two middle values
    double median = 0;
    if (temps.size() % 2) {
        // The odd case
        median = temps[temps.size()/2];
    } else {
        // The even case
        median = ( temps[(temps.size()/2)-1] + temps[temps.size()/2] ) / 2;
    }
    cout << "The median temperature is " << median << ".\n";

    return 0;
}