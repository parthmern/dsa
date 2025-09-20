// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // val, row, col
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > minHeap;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        // 1) insert first ele of each row into minHeap
        for(int i=0; i<nums.size(); i++){
            minHeap.push( make_pair(nums[i][0], make_pair(i, 0)) );
            maxi= max(maxi, nums[i][0]);
        }
        mini = minHeap.top().first;

        // 2)
        vector<int> ans(2);
        ans[0] = mini;
        ans[1] = maxi;

        while(minHeap.size() == nums.size()){
            pair<int, pair<int,int>> top = minHeap.top();
            minHeap.pop();

            int ele = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if(col+1 < nums[row].size()){
                minHeap.push( make_pair(nums[row][col+1], make_pair(row, col+1)) );
                maxi = max(maxi, nums[row][col+1]);
                mini = minHeap.top().first;

                // check range
                if( maxi-mini < ans[1]-ans[0] ){
                    ans[0] = mini;
                    ans[1] = maxi;
                }
            }
        }
        return ans;

    }
};