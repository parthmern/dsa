class Solution {
    public int binarysearch(int[] arr, int k) {
        
        int s = 0;
        int e = arr.length - 1;
        
        int ans = -1;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid] == k){
               ans = mid;
                e = mid - 1;
            }
            
            if(arr[mid]<k){
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
        
    }
}