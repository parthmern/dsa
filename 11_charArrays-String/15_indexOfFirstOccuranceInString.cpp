#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int index = -1;
    for (int i = 0; i < haystack.length(); i++) {
        int j = 0;
        if (haystack[i] == needle[j]) {
            cout << "i is now : " << haystack[i] << endl;
            while (j < needle.length()) {
                if (haystack[i + j] == needle[j]) {
                    cout << "matched" << endl;
                    j++;
                    index = i;
                } else {
                    cout << "not matched" << endl;
                    index = -1;
                    break;
                }
            }
            if (index != -1) {
                cout << "Final matched" << endl;
                return index;
            }
        }
    }
    return index;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    int result = strStr(haystack, needle);
    cout << "Result: " << result << endl;
    return 0;
}
