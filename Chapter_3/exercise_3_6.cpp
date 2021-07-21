#include "../std_lib_facilities.h"
/*
    This program accepts three integer inputs then outputs them in numerical
    sequence in a comma separated format.
*/

int main() {
    vector<int> input;
    cout << "Enter 3 integers: ";
    for (int i = 0; i < 3; i++) {
        int temp_input;
        cin >> temp_input;
        input.push_back(temp_input);
    }

    sort(input);
    
    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
        if (i != 2) { cout << ", "; }
    }

    return 0;
}