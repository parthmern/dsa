#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Sentinel value for base index
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(') {
            st.push(i); // Push index of '(' onto the stack
        } else {
            st.pop(); // Pop the top element
            if (st.empty()) {
                st.push(i); // Push current index as the base for future valid substrings
            } else {
                int len = i - st.top(); // Calculate length of valid substring
                maxLen = max(len, maxLen); // Update max length
            }
        }
    }

    return maxLen;
}

int main() {
    string s = "(()))())("; // Example test case
    cout << "Longest valid parentheses length: " << longestValidParentheses(s) << endl;
    return 0;
}
