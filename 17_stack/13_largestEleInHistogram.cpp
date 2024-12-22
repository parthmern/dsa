#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

vector<int> findNextSmallerElements(const vector<int>& v) {
    stack<int> st;
    st.push(-1);  
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--) {
        int currEle = v[i];
        while (st.top()!=-1 && v[st.top()]>= currEle) {     // acess ele from top index
            st.pop();
        }
        ans[i] = st.top();
        st.push(i); // index insert
    }

    return ans;
}

vector<int> findPreviousSmallerElements(const vector<int>& v) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());

    for (int i = 0; i <v.size(); i++) {
        int currEle = v[i];
        while (st.top()!=-1 && v[st.top()]>= currEle) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i); // inserting index
    }

    return ans;
}

int getRectangularAreaHistogram(vector<int> &height){

    vector<int> prev = findPreviousSmallerElements(height);
    vector<int> next = findNextSmallerElements(height);

    int maxArea = INT_MIN;

    for(int i=0; i<height.size(); i++){
        if(next[i]==-1){
            next[i]=height.size();  // -1 to size
        }

        int len = height[i];
        int width = next[i]-prev[i]-1;
        int area = len*width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << getRectangularAreaHistogram(height);
    
    return 0;
}
