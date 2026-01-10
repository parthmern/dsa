class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        Arrays.sort(nums);
        int n = nums.length;

        HashSet<List<Integer>> ans = new HashSet<>();

        for(int i=0; i<n; i++){

            for(int j=i+1; j<n; j++){
                int k = j+1;
                int l = n-1;

                while( k<l ){

                    // int sum = nums[i] + nums[j] + nums[k] + nums[l]; // [1000000000,1000000000,1000000000,1000000000]
                    // overflow error how to fix
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if(sum>target) l--;
                    else if(sum<target)k++;
                    else{
                        // ans
                        ArrayList<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        temp.add(nums[l]);
                        Collections.sort(temp);
                        ans.add(temp);
                        k++; l--;
                    }
                }

            }

        }

        return new ArrayList<>(ans);

    }
}