class Solution {

    private int peak(int[] arr){

        int s = 0;
        int e = arr.length-1;

        while(s<e){

            int mid = (s+e)/2;
            System.out.println("s"+s + " e"+e + "mid"+mid);
            if( mid-1>=0 && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if( arr[mid] > arr[mid+1] ){
                // you are on second part need to go to left
                e = mid-1;
            }else {
                s = mid+1;
            }

        }

        return s;

    }

    public int findPeakElement(int[] nums) {
        if(nums.length == 1) return 0;
        return peak(nums);

    }
}