#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robHelper(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        int robAmt1 = nums[i] + robHelper(nums, i + 2); // include
        int robAmt2 = robHelper(nums, i + 1);           // exclude

        return max(robAmt1, robAmt2);
    }

    int rob(vector<int>& nums) {
        return robHelper(nums, 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: " << solution.rob(nums) << endl;
    return 0;
}
