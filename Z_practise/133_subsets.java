class Solution {

    private void helper( List<List<Integer>> ans, int index, int[] nums, List<Integer> temp){
        
        if(index>=nums.length ) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        helper(ans, index+1, nums, temp);
        temp.add(nums[index]);
        helper(ans, index+1, nums, temp);
        //temp.remove(Integer.valueOf(index));
        temp.remove(temp.size()-1);
    }

    public List<List<Integer>> subsets(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();
        helper(ans, 0, nums, new ArrayList<>());
        return ans;
        
    }
}