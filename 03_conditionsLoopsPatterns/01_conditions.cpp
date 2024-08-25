#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // if statement
    if (number > 0) {
        cout << "Number is positive.\n";
    }

    // if-else statement
    if (number % 2 == 0) {
        cout << "Number is even.\n";
    } else {
        cout << "Number is odd.\n";
    }

    // if-else if-else statement
    if (number < 0) {
        cout << "Number is negative.\n";
    } else if (number == 0) {
        cout << "Number is zero.\n";
    } else {
        cout << "Number is positive.\n";
    }

    // Nested if statement
    if (number >= 0) {
        if (number == 0) {
            cout << "Number is zero.\n";
        } else {
            cout << "Number is positive.\n";
        }
    } else {
        cout << "Number is negative.\n";
    }

    // switch statement
    switch (number) {
        case 0:
            cout << "Number is zero.\n";
            break;
        case 1:
            cout << "Number is one.\n";
            break;
        case 2:
            cout << "Number is two.\n";
            break;
        default:
            cout << "Number is neither zero, one, nor two.\n";
    }

    // Ternary operator
    string result = (number >= 0) ? "non-negative" : "negative";
    cout << "The number is " << result << ".\n";

    return 0;
}