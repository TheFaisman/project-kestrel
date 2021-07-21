#include "../std_lib_facilities.h"
/*
    Create a program that finds the mode of a set of positive integers.
*/
template <class T>
T find_mode(vector<T> arg_vector) {
    T current_mode = 0;
    T num_of_occurences = 0;
    T max_occurences = 0;
    for (int i = 0; i < arg_vector.size(); i++) {
        for (int j = i; j < arg_vector.size(); j++) {
            if (arg_vector[i] == arg_vector[j]) {
                num_of_occurences++;
            }
        }
        if (num_of_occurences > max_occurences) {
            max_occurences = num_of_occurences;
            current_mode = arg_vector[i];
        }
        num_of_occurences = 0;
    }
    return current_mode;
}

int main() {
    cout << "Enter values of a set of positive integers: ";
    vector<int> input_values;
    for (int temp; cin >> temp;) {
        input_values.push_back(temp);
    }

    int mode = find_mode(input_values);
    cout << "The mode of the set of positive integers is " << mode << ".\n";

    return 0;
}