#include "../std_lib_facilities.h"
/*
    Write a program that takes an input value n and then finds the first n primes.
*/
bool is_prime(int num, vector<int> primes) {
    bool is_prime = true;
    if (num == 1) {
        // 1 is the first prime number.
        return true;
    }
    if (primes.size() > 0) {
        // Only iterate through list of primes if primes is not empty.
        for (int i = primes.size()-1; i >= 0; i--) {
            // Iterate through list of primes backwards. 
            if (num % primes[i] == 0 && primes[i] != 1) {
                // If current number is divisible by a prime and the prime is not 1
                // then the current number is not a prime number.
                is_prime = false;
            }
        }
    }
    return is_prime;
}

template <class T>
void print_vector(vector<T> v) {
    for (T element : v) {
        cout << element << " ";
    }
}

int main() {
    cout << "How many prime numbers would you like to find? ";
    int num_of_primes = 0;
    cin >> num_of_primes;
    cout << "On it! Printing the first " << num_of_primes << " primes.\n";

    vector<int> primes;
    for (int i = 1; primes.size() <= num_of_primes; i++) {
        if (is_prime(i, primes)) {
            primes.push_back(i);
        }
    }

    cout << "Printing " << num_of_primes << " primes.\n";
    print_vector<int>(primes);

    return 0;
}