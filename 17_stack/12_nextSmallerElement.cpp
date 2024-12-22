#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNextSmallerElements(const vector<int>& v) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--) {
        int currEle = v[i];
        while (st.top() >= currEle) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currEle);
    }

    return ans;
}

vector<int> findPreviousSmallerElements(const vector<int>& v) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());

    for (int i = 0; i <v.size(); i++) {
        int currEle = v[i];
        while (st.top() >= currEle) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currEle);
    }

    return ans;
}



int main() {
    vector<int> v = {2, 1, 4, 3};
    vector<int> ans = findNextSmallerElements(v);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = findPreviousSmallerElements(v);

    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << " ";
    }

    return 0;
}
