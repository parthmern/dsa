class Solution {
    
    public int noOfAllocatedStudents(int[] arr, int mid){
        
        int student = 1;
        int sum = 0;
        
        for(int ele : arr){
            
            if( sum + ele > mid ){
                
                //System.out.println("sumele" + (sum + ele) + " " + student );
                
                sum = ele;
                student++;
            }else{
                sum = sum + ele;
            }
            
        }
        
        return student;
        
    }
    
    public int findPages(int[] arr, int k) {
        
        if(arr.length < k) return -1;
        
        int sum = 0;
        int s = arr[0];
        for (int ele : arr) {
            sum += ele;
            s = Math.max(s, ele); // lower bound = largest single element
        }

        int e = sum;
        int ans = -1;

        
        while(s<=e){
            
            int mid = (s+e)/2;
            
            int allocatedStudents = noOfAllocatedStudents(arr, mid);
            
            //System.out.println("ac" + mid + " " + allocatedStudents);
            
            
            if(allocatedStudents > k){
                s = mid+1;
            }else{
                e = mid-1;
                ans = mid;
            }
            
            
        }
        
        return ans;
    
        
    }
}