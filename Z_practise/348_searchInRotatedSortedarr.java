class Solution {

    private int findPivotIdx(int[] arr){

        int s = 0;
        int e = arr.length - 1;

        while(s<e){
            int mid = (s+e)/2;
            if(arr[mid]>arr[e]) s=mid+1;
            else e=mid;
        }

        return s;

    }

    private int bs(int[] arr, int s, int e, int x){

        System.out.println("bs" + s + e);

        while(s<=e){
             System.out.println("bs" + s + e);
            int mid = s + (e - s) / 2;
            System.out.println("mid" + mid);
            if(arr[mid] == x)return mid;

            if(arr[mid] < x) s=mid+1;
            else e=mid-1;
        }

        return -1;

    }

    public int search(int[] nums, int target) {

        int idx = this.findPivotIdx(nums);
        int pivotEle = nums[idx];

        System.out.println("pi" + idx);

        if(target == nums[0]) return 0;
        if(target == pivotEle) return idx;
        if(target == nums[nums.length-1]) return nums.length-1;

        // s -- pivot -- e
        if(idx == 0) return this.bs(nums,0, nums.length-1, target);
        if(idx == nums.length-1) return this.bs(nums,0, nums.length-1, target);

        if(target>nums[0] && target<=nums[idx-1]) return this.bs(nums,0, idx-1, target);
        else return this.bs(nums,idx, nums.length-1, target);
    
    }
}