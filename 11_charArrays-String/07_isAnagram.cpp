#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    int freqTable[256] = {0};

    for (int i = 0; i < s.size(); i++) {
        freqTable[(int)s[i]]++;
    }

    for (int i = 0; i < t.size(); i++) {
        freqTable[(int)t[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freqTable[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";
 
    if (isAnagram(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
