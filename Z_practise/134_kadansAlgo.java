class Solution {
    public int maxSubArray(int[] nums) {

        // never carry neg in your life
        int maxi = Integer.MIN_VALUE;
        int sum = 0;

        for(int ele: nums){

            sum = sum + ele;
            maxi = Math.max(maxi, sum);
            if(sum<0) sum = 0;

        }
        return maxi;
        
    }
}