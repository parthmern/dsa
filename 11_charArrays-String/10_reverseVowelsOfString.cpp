#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    // Check if the character is a vowel (both uppercase and lowercase)
    return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || 
           ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || 
           ch == 'u' || ch == 'U';
}

string reverseVowels(string s) {
    int l = 0;
    int h = s.length() - 1;

    // Two-pointer approach to reverse vowels
    while (l < h) {
        if (isVowel(s[l]) && isVowel(s[h])) {
            swap(s[l], s[h]);
            l++;
            h--;
        } else if (!isVowel(s[l])) {
            l++;
        } else if (!isVowel(s[h])) {
            h--;
        }
    }
    
    return s;
}

int main() {
    string s = "IceCreAm";
    cout << reverseVowels(s) << endl; // Expected output: "AceCreIm"
    return 0;
}
