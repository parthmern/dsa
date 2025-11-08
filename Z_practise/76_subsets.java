class Solution {

    public static List<List<Integer>> ans = new ArrayList<>();

    public void helper(int[] nums, int i, List<Integer> temp){

        if( i == nums.length ){
            ans.add(new ArrayList<>(temp));  
            return;
        }
        helper(nums, i+1, temp);
        temp.add(nums[i]);
        helper(nums, i+1, temp);
        temp.remove(temp.size() - 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        ans.clear(); 
        helper(nums, 0, new ArrayList<Integer>());
        return ans;
        
    }
}