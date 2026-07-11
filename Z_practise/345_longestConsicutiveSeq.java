class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length ==0) return 0;
        Arrays.sort(nums);

        System.out.println(Arrays.toString(nums));
        
        int ans = 1;

        int finalAns = 0;
        int lastEle = nums[0];

        for(int i=1; i<nums.length; i++){

            int ele = nums[i];

            if(ele == lastEle){
                continue;
            }
            else if(ele == lastEle+1){
                lastEle = nums[i];
                ans++;
            }else{
                finalAns = Math.max(finalAns, ans);
                ans = 1;
                lastEle = nums[i];
            }

        }
        finalAns = Math.max(finalAns, ans);
        return finalAns;

    }
}