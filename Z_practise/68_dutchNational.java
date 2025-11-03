class Solution {

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void sortColors(int[] nums) {

        int s = 0;
        int e = nums.length-1;
        int p = 0;

        while(p<=e){
            if(nums[p]==0){
                swap(nums, s, p);
                s++;
                p++;
            }else if(nums[p]==1){
                p++;
            }else{
                swap(nums, p, e);
                e--;
            }
        }
        
    }
}