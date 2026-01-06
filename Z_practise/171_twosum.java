class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] ans = new int[2];
        for(int i=0; i<nums.length; i++){
            int needed = target - nums[i];
            if(map.get(needed) == null){
                map.put(nums[i], i);
            }else{
                ans[0] = i;
                ans[1] = map.get(needed);
                return ans;
                //return new int{i, map.get(needed)};
            }
        }
        return ans;
    }
}