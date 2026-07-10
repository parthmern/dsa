class Solution {
    public int subarraySum(int[] nums, int k) {

        Map<Integer, Integer> prefixSum = new HashMap<>();

        // Empty prefix has occurred once
        prefixSum.put(0, 1);

        int sum = 0;
        int ans = 0;

        for (int num : nums) {

            sum += num;

            // Count all previous prefix sums equal to (sum - k)
            ans += prefixSum.getOrDefault(sum - k, 0);

            // Record current prefix sum
            prefixSum.put(sum, prefixSum.getOrDefault(sum, 0) + 1);
        }

        return ans;
    }
}