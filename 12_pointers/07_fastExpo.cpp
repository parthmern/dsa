#include <iostream>

using namespace std;

int fastExpo(int a, int b) {
    int ans = 1;

    while (b > 0) {
        // If b is odd, multiply ans by a
        if (b & 1) {
            ans = ans * a;
        }
        // Square the base
        a = a * a;
        // Divide b by 2
        b = b >> 1;
    }

    return ans;
}

int main() {
    int base, exponent;
    // cout << "Enter base: ";
    // cin >> base;
    // cout << "Enter exponent: ";
    // cin >> exponent;

    int result = fastExpo(2, 5);
    cout << "Result: " << result << endl;

    return 0;
}
