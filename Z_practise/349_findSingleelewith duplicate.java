class Solution {

    private int sol(int[] arr){

        int s = 0;
        int e = arr.length-1;

        while(s<e){

            int mid = (s+e)/2;
            boolean isOdd = mid % 2 != 0;

            if(mid>0 && mid<arr.length-1 && arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return mid;

            if(isOdd){

                if(arr[mid-1] == arr[mid]) s = mid+1;
                else e = mid-1;
            }else{
                // mid is even
                if(arr[mid-1] == arr[mid]) e = mid-1;
                else s= mid+1;
            }

        }

        return s;

    }

    public int singleNonDuplicate(int[] nums) {

        if(nums.length == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.length-1] != nums[nums.length-2]) return nums[nums.length-1];
        
        int idx = this.sol(nums);

        if(idx == -1) return -1;

        return nums[idx];
        
    }
}