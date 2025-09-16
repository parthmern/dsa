// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int solve(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        // first k process kr do
        for (int i = 0; i < k; i++) {
            int ele = arr[i];
            pq.push(ele);
        }

        // remaining ele ko tabhi insert karenge jab wo top se chote honge
        for (int i = k; i < arr.size(); i++) {
            int ele = arr[i];
            if (ele > pq.top()) {
                pq.pop();
                pq.push(ele);
            }
        }

        return pq.top();
    }

    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};