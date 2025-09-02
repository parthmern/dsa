class Solution {
public:
    stack<char> st;

    void solve(string& s, int i) {

        if (i == s.size()) {
            return;
        }

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            // opening bracket
            st.push(s[i]);
        } else {
            // closing bracket
            char temp = st.top();
            if ((s[i] == ')' && temp == '(') || (s[i] == '}' && temp == '{') ||
                (s[i] == ']' && temp == '[')) {
                st.pop();
            }
        }

        solve(s, i + 1);
    }

    bool isValid(string s) {

        solve(s, 0);
        return st.empty() ? true : false;
    }
};