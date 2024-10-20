#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string reorganizeString(string s) {
    // Frequency array for counting characters
    int hash[26] = {0};

    // Fill frequency array
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    // Find the most frequent character
    char mostFreqChar;
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
            mostFreqChar = i + 'a';
        }
    }

    // If the most frequent character appears more than (n + 1) / 2 times, return ""
    if (maxFreq > (s.size() + 1) / 2) {
        return "";
    }

    // Place the most frequent character at even indices
    int index = 0;
    while (maxFreq > 0) {
        s[index] = mostFreqChar;
        maxFreq--;
        index += 2;
    }

    // Mark the most frequent character as used
    hash[mostFreqChar - 'a'] = 0;

    // Place the rest of the characters
    for (int i = 0; i < 26; i++) {
        while (hash[i] > 0) {
            if (index >= s.size()) {
                index = 1; // Start filling odd indices if we reach the end
            }
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    return s;
}

int main() {
    string s = "aab";
    string result = reorganizeString(s);

    if (result.empty()) {
        cout << "Cannot reorganize the string to avoid adjacent duplicates." << endl;
    } else {
        cout << "Reorganized string: " << result << endl;
    }

    return 0;
}
