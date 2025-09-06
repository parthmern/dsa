#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<string> st;

    string decodedString(string &s) {
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            string current(1, ch);

            if (current == "]") {
                string temp = "";
                string ans = "";
                int num = 0;

                // collect letters until “[”
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;   // prepend instead of append
                    st.pop();
                }
                if (!st.empty() && st.top() == "[") {
                    st.pop(); // pop “[”
                }

                // collect number
                string tempNum = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    tempNum = st.top() + tempNum; // prepend
                    st.pop();
                }
                num = stoi(tempNum);

                // repeat substring
                while (num--) {
                    ans += temp;
                }

                st.push(ans);
            } else {
                st.push(current);
            }
        }

        string finalAns = "";
        while (!st.empty()) {
            finalAns = st.top() + finalAns; // prepend // instead of append and doing reverse in end
            st.pop();
        }

        return finalAns; // ❌ no reverse here
    }
};
