// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// User function template for C++

class Solution {
  public:
    
    int solve(vector<int> &arr, int k){
        priority_queue<int> pq;
        // first k process kr do
        for(int i=0; i<k; i++){
            int ele = arr[i];
            pq.push(ele);
        }
        
        // remaining ele ko tabhi insert karenge jab wo top se chote honge
        for(int i=k; i<arr.size(); i++){
            int ele = arr[i];
            if(ele<pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        
        return pq.top();
    }
    
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        return solve(arr,k);
    }
};