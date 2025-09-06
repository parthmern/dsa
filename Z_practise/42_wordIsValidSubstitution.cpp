class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == 'c') {
                // To form "abc", stack must have ... 'a', 'b' before 'c'
                if (st.size() < 2) return false;

                char b = st.top(); st.pop();
                char a = st.top(); st.pop();

                if (a != 'a' || b != 'b') return false;
            } else {
                // push 'a' or 'b'
                st.push(ch);
            }
        }
        return st.empty();
    }
};
