#include "../std_lib_facilities.h"
/*
    Create a program to find all the prime numbers between 1 and 100.
    One way to do this is to write a function that will check if a number
    is prime (see if the number can be divided by a prime number smaller
    than itself).
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

int main() {
    constexpr int max = 200;

    vector<int> primes;
    int last_prime;
    for (int i = 1; i <= max; i++) {
        if (is_prime(i, primes)) {
            primes.push_back(i);
        }
    }

    cout << "List of prime numbers between 1 and " << max << ".\n";
    for (int prime : primes) {
        cout << prime << " ";
    }
    return 0;
}