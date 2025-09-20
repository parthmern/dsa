// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

class Solution {
  public:
    
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    void solve(vector<int> &arr, int k){
        for(int i=0; i<arr.size(); i++){
            int sum = 0;
            for(int j=i; j<arr.size(); j++){
                sum = sum + arr[j];
                
                if(minHeap.size() < k){
                    minHeap.push(sum);
                }else{
                    if(minHeap.top() < sum){
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
            }
        }
    }
  
    int kthLargest(vector<int> &arr, int k) {
        solve(arr, k);
        return minHeap.top();
    }
};