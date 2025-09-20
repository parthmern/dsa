// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

class Solution {
  public:
    
    priority_queue<int> maxHeap;    // left half (smaller numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap;    // right half (bigger numbers)
    
    void insertHeap(int &x) {
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
    }
    
    void balanceHeap() {
        // ensure |size(maxHeap) - size(minHeap)| <= 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double getMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;  // average
        } else {
            return maxHeap.top();  // maxHeap will always have 1 extra if odd
        }
    }
  
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        for (int x : arr) {
            insertHeap(x);
            balanceHeap();
            ans.push_back(getMedian());
        }
        return ans;
    }
};
