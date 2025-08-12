class Solution {
public:
    int bs(vector<int>& nums, int s, int e, int target) {
        int mid = (s + e) / 2;

        if(s>e) return -1;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid]<target) {
            return bs(nums, mid+1, e, target);
        }else{
            return bs(nums, s, mid-1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target );
    }
};