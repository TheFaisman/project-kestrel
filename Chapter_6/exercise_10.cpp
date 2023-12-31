#include <iostream>

#include "../std_lib_facilities.h"
/*
    A permutation is an ordered subset of a set. For example, say you wanted to pick a combination
    to a vault. There are 60 possible numbers, and you need three different numbers for the combination.
    There are P(60,3) permutations for the combinations, where P is defined by 
    
        P(a,b) = a! / (a-b)!

    Combinations are similar to permutations, except that the order doesn't matter. The formula is

        C(a,b) = P(a,b) / b!

    Design a program that asks users for two integers, and asks them whether they want to calculate
    permutations or combinations, and prints the result.
*/

int Factorial(const int& n) {
    if (n < 0) {
        error("Cannot take the factorial of a negative number.");
    }

    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}

int Permutation(int a, int b) {
    if (b > a) {
        error("B cannot be greated than A.");
    }
    return (Factorial(a) / Factorial(a-b));
}

int Combination(int a, int b) {
    return (Permutation(a, b) / Factorial(b));
}

int GetNumberInput() {
    int num = 0;
    
    char n = 'u';
    std::cin >> n;
    switch (n) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            std::cin.putback(n);
            std::cin >> num;
            break;
        case 'q':
            num = -1;
            break;
        case '-':
            error("Input cannot be a negative integer.");
            break;
        default:
            error("Input is not an integer.");
            break;
    }
    return num;
}

int main() {
    std::cout << "Please provide two integers followed by the operation (P or C)." << std::endl;
    std::cout << "Input 'q' at any point to quit the program." << std::endl;

    while (std::cin) {
        std::cout << "A: ";
        int a = GetNumberInput();
        if (a == -1) {
            return 0; // Received request to end
        }

        std::cout << "B: ";
        int b = GetNumberInput();
        if (b == -1) {
            return 0; // Received request to end
        }

        if (b > a) {
            error("B cannot be greater than A.");
        }

        char op = 'u';
        std::cout << "P or C: ";
        std::cin >> op;
        switch (op) {
            case 'P': case 'p':
                std::cout << "Permutation: " << Permutation(a, b) << std::endl;
                break;
            case 'C': case 'c':
                std::cout << "Combination: " << Combination(a, b) << std::endl;
                break;
            case 'q':
                return 0; // Received request to end
            default:
                error("Invalid operation. Must be P or C.");
                break;
        }
    }
    return 0;
}