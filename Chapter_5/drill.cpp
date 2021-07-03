#include "../std_lib_facilities.h"

/*
    Chapter 5: Errors
    Drill
*/

int main() {
    try {
        // Your code here
        vector<int> v(6);
        for (int i = 0; i <= v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "Success!\n";
        return 0;
    } catch (exception &e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Oops! Unknown exception.\n";
        return 2;
    }
    return 0;
}