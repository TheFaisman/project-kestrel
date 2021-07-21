#include "../std_lib_facilities.h"

int main() {
    
    vector<string> input;
    cout << "Enter 3 strings: ";
    for (int i = 0; i < 3; i++) {
        string temp_input;
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