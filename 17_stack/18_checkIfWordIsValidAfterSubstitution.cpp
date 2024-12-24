// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions

class Solution {
public:
    bool isValid(string s) {

        if (s[0] != 'a') {
            // means string ki starting he 'b' or 'c' se ho rhi
            return false;
        }
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a') {
                st.push(ch);
            } else if (ch == 'b') {
                if (!st.empty() && st.top() == 'a') {
                    st.push(ch);
                } else {
                    return false;
                }
            } else {
                // ch = 'c' hai to
                if (!st.empty() && st.top() == 'b') {
                    st.pop();

                    if (!st.empty() && st.top() == 'a') {
                        st.pop();
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