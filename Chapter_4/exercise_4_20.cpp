#include "../std_lib_facilities.h"
/*
    Modify the last exercise to have an input mode and a lookup mode.
    In lookup mode, when you enter a name the program should output the 
    corresponding score or "name not found".

    If the user enters an integer, the program will output all the names
    with that score or "score not found".
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

void insert_mode(vector<string> names, vector<int> scores);
void lookup_mode();

int main() {
    vector<string> names;
    vector<int> scores;

    string name = " ";
    int score = 0;

    cout << "Printing names and scores...\n";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " " << scores[i] << endl;
    }    
    return 0;
}

void insert_mode(vector<string> names, vector<int> scores) {
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
}

void lookup_mode(vector<string> names, vector<int> scores) {
    cout << "Would you like to look up the score associated with a name or names associated with a score? (s/n): ";
    char input;
    cin >> input;

    switch (input) {
    case 's':
        cout << "Please enter a score: ";
        int score;
        cin >> score;
        lookup_names_by_score(names, scores, score);
        break;
    
    default:
        break;
    }
}

vector<string> lookup_names_by_score(vector<string> names, vector<int> scores, int score) {
    vector<string> looked_up_names;
    bool found = false;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] == score) {
            looked_up_names.push_back(names[i]);
            found = true;
        }
    }
    if (!found) {
        simple_error("Data not found.");
    }
    return looked_up_names;
}

int lookup_score_by_name(vector<string> names, vector<int> scores, string name) {
    int looked_up_score = 0;
    bool found = false;
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            looked_up_score = scores[i];
            found = true;
        }
    }
    if (!found) {
        simple_error("Data not found.");
    }
    return looked_up_score;
}