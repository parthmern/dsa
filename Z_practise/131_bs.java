class Solution {
    public int binarysearch(int[] arr, int k) {
        
        int s = 0;
        int e = arr.length-1;
        
        int mid = (s+e)/2;
        
        while(s<=e){
            
            int midVal = arr[mid];
            
            if(midVal == k) return mid;
            
            if(midVal < k) {
                s = mid+1;
            }else{
                e = mid-1;
            }
            
            mid = (s+e)/2;
        }
        
        return -1;
    }
}