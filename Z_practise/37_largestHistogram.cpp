class Solution {
public:
    

    stack<int>st;
    int ans = INT_MIN;

    void findPrevSmallestEle(vector<int>& heights, vector<int>& prevSamllestEle){

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSamllestEle[i] = st.top();
            }
            st.push(i);
        }
    }
    
        void findNextSmallestEle(vector<int>& heights, vector<int>& nextSamllestEle){

        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSamllestEle[i] = st.top();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> prevSamllestEle(heights.size(), -1);
        findPrevSmallestEle(heights, prevSamllestEle);
        while(!st.empty()){
            st.pop();
        }
        vector<int> nextSamllestEle(heights.size(), -1);
        findNextSmallestEle(heights, nextSamllestEle);

        for(auto val: prevSamllestEle ) cout << val;

        cout << endl;

        for(auto val: nextSamllestEle ) cout << val;

        for(int i=0; i<heights.size(); i++){
            int h = heights[i];
            int w = (nextSamllestEle[i] == -1 ? heights.size() : nextSamllestEle[i]) - prevSamllestEle[i] - 1;
            int a = h * w;
            ans = max(ans, a);
        }

        return ans;
        

    }
};