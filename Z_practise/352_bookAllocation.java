class Solution {
    
    private long howManyBooks(int[] arr, int days, long mid){

        long ans = 0;
        long prex = 0;
        for(int ele: arr){

            prex+=ele;
            
            if(prex>mid){
                ans++;
                prex = ele;
            }

            if(mid == prex){
                ans++;
                prex = 0;
            }
            

        }

        if(prex!=0 && prex <= mid) ans++;

        return ans;

    }
    
    public int findPages(int[] arr, int k) {
        
        if (k > arr.length) {
            return -1;
        }

        // code here
        
        long  mini = Integer.MAX_VALUE;
        long sum = 0;

        long maxi = Integer.MIN_VALUE;

        for(int ele: arr){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
            sum+=ele;
        }

        long s = maxi;
        long e = sum;

        long res = -1;

        while (s <= e) {
            long mid = s + (e - s) / 2;
            long students = howManyBooks(arr, k, mid);
        
            if (students <= k) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return (int)res;
        
    }
}