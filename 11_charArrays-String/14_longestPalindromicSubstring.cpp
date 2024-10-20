#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& sub, int start, int end) {
    while (start < end) {
        if (sub[start] != sub[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int main() {
    string s = "babad";
    string result = longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
