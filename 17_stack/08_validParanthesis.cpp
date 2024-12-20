// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // closing bracket
                if (!st.empty()) {
                    char topch = st.top();
                    if (ch == ')' && topch == '(') {
                        st.pop();
                    } else if (ch == '}' && topch == '{') {
                        st.pop();
                    } else if (ch == ']' && topch == '[') {
                        st.pop();
                    } else {
                        // bracket not matching
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};