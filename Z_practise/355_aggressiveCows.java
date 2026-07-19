class Solution {
    
    private int howManyCows(int[] arr, int k){
            
        int ans = 1;
        int lastIndex = 0;
        
        for(int i=0; i<arr.length; i++){
            int ele = arr[i];
            int lastPos = arr[lastIndex];
            
            int now = ele-lastPos;
            //now = now<0 ? (now*(-1)) : now;
            
            if(now>=k){
                lastIndex = i;
                ans++;
            }
        }
        
        return ans;
        
    }
    
    public int aggressiveCows(int[] arr, int k) {
        // code here
        
        Arrays.sort(arr);
        
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        
        for(int ele: arr){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
        }
        
        int s = 0;
        int e = maxi-mini;
        
        int ans = -1;
        
        while(s<=e){
            
            int mid = (s+e)/2;
            int cows = this.howManyCows(arr, mid);
            
            //System.out.println("mid " + mid + " => " + cows);
            
            if(cows==k) ans = mid;
            
            if(cows>=k){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
            
        }
        
        return ans;
        
    }
}