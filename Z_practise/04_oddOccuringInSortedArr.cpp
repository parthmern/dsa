// https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;
        int mid = (s+e)/2;

        while (s < e) {

            if( mid == 0 ){
                if( nums[mid] != nums[mid + 1]  ) return nums[mid];
            }

            if ( nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            // mid is even
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    // we are on left side
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }else{
                // mid is odd
                if( nums[mid] == nums[mid - 1] ){
                    // we are on left side
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            mid = (s+e)/2;
        }

        return nums[s];
    }
};