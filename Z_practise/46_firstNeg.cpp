class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;         // store indices of negative numbers
        vector<int> ans;

        for(int i = 0; i < k ; i++) {
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        ans.push_back(q.empty() ? 0 :arr[q.front()]);
        
        for(int i = k; i < arr.size(); i++) {
            while(!q.empty() && i-k>=q.front()){
                //cout << " i ->" << i << " poped is" << q.front() << endl;
                q.pop();
            }
            
            if(arr[i] < 0){
                q.push(i);
            }
            ans.push_back(q.empty() ? 0 : arr[q.front()]);
        }

        return ans;
    }
};
