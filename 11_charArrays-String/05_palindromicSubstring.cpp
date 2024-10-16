#include <iostream>
#include <string>

using namespace std;

// Function to expand around the given indices and count palindromic substrings
int expandAroundIndex(string s, int i, int j) {
    int count = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j]) {
        count++;
        i--;
        j++;
    }
    return count;
}

// Function to count the number of palindromic substrings in a string
int countSubstrings(string s) {
    int totalCount = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        // Count odd-length palindromes centered at s[i]
        int oddKaAns = expandAroundIndex(s, i, i);
        totalCount += oddKaAns;

        // Count even-length palindromes centered between s[i] and s[i+1]
        int evenKaAns = expandAroundIndex(s, i, i + 1);
        totalCount += evenKaAns;
    }

    return totalCount;
}

int main() {
    string input = "abc";
    // cout << "Enter a string: ";
    // cin >> input;

    int result = countSubstrings(input);
    cout << "The number of palindromic substrings is: " << result << endl;

    return 0;
}
