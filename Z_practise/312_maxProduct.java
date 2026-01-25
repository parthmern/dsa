class Solution {
    public int maxProduct(int[] nums) {

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.length; i++) {

            int x = nums[i];

            int tempMax = Math.max(x, Math.max(x * maxSoFar, x * minSoFar));
            int tempMin = Math.min(x, Math.min(x * maxSoFar, x * minSoFar));

            maxSoFar = tempMax;
            minSoFar = tempMin;

            ans = Math.max(ans, maxSoFar);
        }

        return ans;
    }
}