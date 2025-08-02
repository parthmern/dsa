https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
    public int findDuplicate(int[] nums) {
        
     for(int i=0; i<nums.length; i++){
        int currentNum = nums[i];
        if(currentNum < 0) {
            currentNum = currentNum * (-1);
        }
        if(nums[currentNum]<0){
            return currentNum;
        }else{
            nums[currentNum]*=(-1);
        }
     }

     return -1;

    }
}

