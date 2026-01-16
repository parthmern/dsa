class Solution {
    
    
    private int howManyCows(int[] arr, int mid){
        
        int count = 0;
        int curr = arr[0];
        
        for(int i=0; i<arr.length; i++){
            
            if( arr[i] - curr >= mid ){
                count++;
                curr=arr[i];
            }
            
        }
        
        return count+1;
        
    }
    
    public int aggressiveCows(int[] stalls, int k) {
        
        Arrays.sort(stalls);
        // code here
        
        if (k > stalls.length) return -1;
        // code here
        
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        int sum = 0;
        
        for(int ele: stalls){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
            sum = sum + ele;
        }
        
        int s = 0;
        int e = maxi-mini;
        
        int res = -1;
        
        
        while(s<=e){
            
            //System.out.println("s"+s+"e"+e);
            
            int mid = (s+e)/2;
            
            int ans = howManyCows(stalls, mid);
            
          //System.out.println("for mid " +mid +" got " + ans);
            
          if (ans >= k) {
                res = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            
        }
        
        return res;
        
        
        
        
    }
}