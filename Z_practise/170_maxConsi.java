class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int i=0;
        int j=0;
        int n=nums.length;
        // if(n==1){
        //     return nums[0];
        // }

        int ans = Integer.MIN_VALUE;

        while(j<n && i<n){

            int count = 0;
            while( nums[i] == nums[j] ){
                if(nums[i] != 0) count++;
                j++;
                ans = Math.max(ans, count);
                if(j>=n) return ans;
            }
            
            i++;
            j=i;
        }

        return ans;
    }
}