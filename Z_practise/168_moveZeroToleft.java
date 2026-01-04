class Solution {

    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void moveZeroes(int[] nums) {
        
        int i=0;
        int j=0;

        while(j<nums.length && i<nums.length){
            
            boolean isZeroDetected = false;
            while(nums[j]==0){
                j++;
                isZeroDetected = true;
                if(j>=nums.length) return;
            }
            //System.out.println(i+" "+j);
            if(isZeroDetected)swap(nums, i, j);
            i=i+1;
            j=i;
            //System.out.println(Arrays.toString(nums));
        }



    }
}