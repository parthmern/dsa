#include <iostream>
#include <vector>
#include <algorithm> // for reverse()
using namespace std;

int main() {
    int a[] = {9, 3, 9};
    int b[] = {6, 1};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int i = n - 1;
    int j = m - 1;

    vector<int> ans;
    int carry = 0;

    // Process both arrays while both have digits left
    while (i >= 0 && j >= 0) {
        cout << "inner: i = " << i << ", j = " << j << endl;

        int sum = a[i] + b[j] + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);

        i--;
        j--;
    }

    // If a[] has remaining digits
    while (i >= 0) {
        cout << "inner two-> i = " << i << endl;

        // assume b[j] is not available so zero
        int sum = a[i] + 0 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);

        i--;
    }

    // If b[] has remaining digits
    while (j >= 0) {
        cout << "inner three-> j = " << j << endl;

        int sum = 0 + b[j] + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);

        j--;
    }

    // If there's any remaining carry
    if (carry) {
        cout << "remaining carry: " << carry << endl;
        ans.push_back(carry);
    }

    // Reverse the result since it's stored in reverse order
    reverse(ans.begin(), ans.end());

    // Print the result
    cout << "Sum: ";
    for (int digit : ans) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
