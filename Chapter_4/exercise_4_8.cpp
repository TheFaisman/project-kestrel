#include "../std_lib_facilities.h"
/*
    Write a program to calculate how many squares on a chess board are required
    to give the inventor at least 1000 grains of rice, at least 1,000,000 grains
    of rice, and at least 1,000,000,000 grains.
*/
constexpr int total_squares = 64;

int main() {
    int total_rice = 0;
    int squares_for_1K = 0;
    int squares_for_1M = 0;
    int squares_for_1B = 0;
    for (int i = 1; i <= total_squares; i++) {
        (i == 1) ? total_rice = 1 : total_rice *= 2;
        
        cout << "Square number: " << i << "\t";
        cout << "Grains of rice: " << total_rice << endl;
        
        if (total_rice >= 1000 && squares_for_1K == 0) {
            squares_for_1K = 1;
        } else if (total_rice >= 1000000 && squares_for_1M == 0) {
            squares_for_1M = i;
        } else if (total_rice >= 1000000000 && squares_for_1B == 0) {
            squares_for_1B = i;
        }
    }

    cout << "It takes " << squares_for_1K << " squares to obtain at least 1K grains of rice.\n";
    cout << "It takes " << squares_for_1M << " squares to obtain at least 1M grains of rice.\n";
    cout << "It takes " << squares_for_1B << " squares to obtain at least 1B grains of rice.\n";
    return 0;
}