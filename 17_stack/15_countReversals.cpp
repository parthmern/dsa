// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

#include <iostream>
#include <stack>
using namespace std;

void validParanthesis(stack<char>& st, string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            st.push('{'); // Push opening bracket
        } else {
            // If it's a closing bracket
            if (!st.empty() && st.top() == '{') {
                st.pop(); // Valid match, pop the opening bracket
            } else {
                st.push('}'); // Push closing bracket
            }
        }
    }
}

int countRev(string s) {
    if (s.size() % 2 != 0) return -1; // Odd size cannot be balanced

    int count = 0;
    stack<char> st;

    validParanthesis(st, s);

    // Count the mismatched brackets
    while (!st.empty()) {
        char one = st.top();
        st.pop();
        char two = st.top();
        st.pop();

        if (one == '{' && two == '{') {
            count += 1; // Two opening brackets need one reversal
        } else if (one == '}' && two == '}') {
            count += 1; // Two closing brackets need one reversal
        } else {
            count += 2; // One opening and one closing bracket need two reversals
        }
    }

    return count;
}

int main() {
    string s = "}{{}}{{{";
    cout << countRev(s) << endl; // Example usage
    return 0;
}
