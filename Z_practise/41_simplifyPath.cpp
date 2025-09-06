class Solution {
public:
    stack<string> st;
    string ans;

    void insertAtBottom(stack<string>& st, string target) {
        if (st.empty()) {
            st.push(target);
            return;
        };

        string top = st.top();
        st.pop();
        insertAtBottom(st, target);
        st.push(top);
    }

    void revStack(stack<string>& st) {
        if (st.empty())
            return;

        string top = st.top();
        st.pop();
        revStack(st);
        insertAtBottom(st, top);
    }

    string simplifyPath(string path) {

        int s = 0;
        int e = s + 1;

        while (s < path.length()) {
            while (e < path.length() && path[e] != '/') {
                e++;
            }

            cout << s << e << endl;

            string minStr = path.substr(s + 1, e - s - 1);
            cout << minStr << endl;
            s = e;
            e = s + 1;

            if (minStr == "" || minStr == ".")
                continue;

            if (minStr == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(minStr);
            }
        }

        if (st.empty()) {
            return "/";
        }

        revStack(st);

        while(!st.empty()){
            string temp = st.top();
            ans += "/" + temp;
            cout <<  temp ;st.pop();
        }

        cout << "ans" << ans;

        return ans;
    }
};
