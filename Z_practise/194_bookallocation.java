class Solution {
    
    private int howManyStudents(int[] arr, int mid){
        
        int count = 1;
        int sum = 0;
        
        for(int ele: arr){
            
            if( ele + sum > mid ){
                count++;
                sum=ele;
            }else{
                 sum = sum+ele;
            }
            
           
        }
        
        return count;
        
        
    }
    
    public int findPages(int[] arr, int k) {
        
        if (k > arr.length) return -1;
        // code here
        
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        int sum = 0;
        
        for(int ele: arr){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
            sum = sum + ele;
        }
        
        int s = maxi;
        int e = sum;
        
        int res = -1;
        
        while(s<=e){
            
            int mid = (s+e)/2;
            int ans = howManyStudents(arr, mid);
            
            //System.out.println("for mid " +mid +" got " + ans);
            
            if( ans <= k ){
                
                // 
                e = mid-1;
                //s= mid+1;
                res = mid;
                
            }else{
                s= mid+1;
                //e=mid+1;
            }
            
            
        }
        
        return res;
        
        
    }
}