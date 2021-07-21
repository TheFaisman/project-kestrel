#include "../std_lib_facilities.h"
/*
    Write a program where you first enter a set of name-and-value pairs,
    such as Joe 17 and Barbara 22. For each pair, add the name to a vector
    called names and the number to a vector called scores.

    Terminate input with NoName 0. Check that each name is unique and terminate
    with an error message if a name is entered twice. Write out all the (name, score)
    pairs, one per line.
*/
template <class T>
bool is_contained_in(T input, vector<T> v) {
    for (T element : v) {
        if (input == element) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> names;
    vector<int> scores;

    string name = " ";
    int score = 0;

    while (cin >> name >> score) {
        if (name == "NoName" && score == 0) {
            break;
        } else {
            if (is_contained_in(name, names)) {
                simple_error("Name already exists.");
            }
            names.push_back(name);
            scores.push_back(score);
        }
    }

    cout << "Printing names and scores...\n";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << scores[i] << endl;
    }    
    return 0;
}