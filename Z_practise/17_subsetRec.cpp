class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int i, vector<int> output) {
        if (i >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude 
        solve(nums, i + 1, output);

        // Include
        output.push_back(nums[i]);
        solve(nums, i + 1, output);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        solve(nums, 0, output);
        return ans;
    }
};
