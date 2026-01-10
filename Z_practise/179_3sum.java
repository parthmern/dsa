class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        HashSet<List<Integer>> ans = new HashSet<>();

        int n = nums.length;
        Arrays.sort(nums);
        for( int i=0; i<n; i++ ){
            
            int ele = nums[i];
            // apply 2 sum logic
            int j = i + 1;
            int k = n - 1;
            while( j<k ){

                int target = nums[i]+nums[j]+nums[k];

                if(target < 0) j++;
                else if(target > 0) k--;
                else{
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    Collections.sort(temp);
                    ans.add(temp);
                    j++;
                    k--;
                }

            }

        }

        return new ArrayList<>(ans);

    }
}