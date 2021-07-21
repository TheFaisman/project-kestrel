#include "../std_lib_facilities.h"

int main() {

    cout << "Enter the name of the person you want to write to: ";

    string first_name;
    string last_name;
    cin >> first_name >> last_name;
    
    cout << endl;
    cout << "Dear " << first_name << ",\n" << endl;

    cout << "\tHow are you doing? It's been quite a while since we've spoken. I hope you've been doing well.";
    cout << "I've been on vacation! So far it's been great, it's so good to see family again.";
    cout << " Unfortunately sometimes we get into arguments but that's how family goes right?";
    
    cout << "\nEnter the name of a friend: ";
    string friend_name;
    cin >> friend_name;
    cout << "\nHave you seen " << friend_name << " lately?";

    cout << "\nEnter the friend's gender (m/f): ";
    char friend_gender;
    cin >> friend_gender;
    
    if (friend_gender == 'm' || friend_gender == 'M') {
        cout << "\nIf you see " << friend_name << " please ask him to call me.";
    } else if (friend_gender == 'f' || friend_gender == 'F') {
        cout << "\nIf you see " << friend_name << " please ask her to call me.";
    } else {
        simple_error("Not a valid input!");
    }

    cout << "\nEnter the age of the recipient: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 110) {
        simple_error("You're kidding!");
    } else {
        cout << "I hear you just had a birthday and you're " << age << " years old! ";
    }

    if (age < 12) {
        cout << "Next year you will be " << age+1 << ".";
    } else if (age == 17) {
        cout << "Next year you will be able to vote.";
    } else if (age > 70) {
        cout << "I hope you're enjoying retirement.";
    }

    cout << "\n\nYours sincerely," << endl << endl;
    cout << "Faisal Naqaweh";

    return 0;
}