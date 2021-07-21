#include "../std_lib_facilities.h"

/*
    End of chapter 4 drill.
*/

constexpr double cm_per_m = 100;
constexpr double cm_per_in = 2.54;
constexpr double in_per_ft = 12;

int main() {
    
    double input_num = 0;
    string unit = " ";
    double min, max = 0;
    double sum = 0;
    int loop_counter = 0;
    bool min_max_set = false;
    vector<double> value_vector;

    cout << "Please provide distance values (in cm, m, in, or ft) to the program.\n";
    cout << "Terminate your input by entering the | character. ";

    while (cin >> input_num >> unit) {
        // Unit error checking
        if (unit != "cm" && unit != "in" && unit != "ft" && unit != "m") {
            simple_error("I don't know the unit " + unit);
        }

        // Printing the newly received input
        cout << "New input: " << input_num << ". ";

        // Convert input unit into m if need be
        if (unit == "cm") { input_num /= cm_per_m; }
        if (unit == "in") {
            input_num *= cm_per_in;
            input_num /= cm_per_m;
        }
        if (unit == "ft") {
            input_num *= in_per_ft;
            input_num *= cm_per_in;
            input_num /= cm_per_m;
        }
        // Store the converted values into a vector
        value_vector.push_back(input_num);

        if (!min_max_set) {
            min = input_num;
            max = input_num;
            min_max_set = true;
            cout << "First number is both smallest and largest.\n";
        }
        if (input_num < min && min_max_set) {
            min = input_num;
            cout << "Smallest number yet!\n";
        }
        if (input_num > max && min_max_set) {
            max = input_num;
            cout << "Largest number yet!\n";
        }

        sum += input_num;
        ++loop_counter;
        cout << "Sum of values: " << sum << " m\n";
        cout << "Number of values: " << loop_counter << "\n";
    }

    sort(value_vector);
    cout << "Final vector of values (in meters):\n";
    for (double i : value_vector) {
        cout << i << " ";
    }
    return 0;
}