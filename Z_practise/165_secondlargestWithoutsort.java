class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        
        int lar = arr[0];
        
        for(int i=0; i<arr.length; i++){
            
            if( arr[i] > lar){
                lar = arr[i];
            }
            
        }
        
        int sec = Integer.MIN_VALUE;
        
        for(int i=0; i<arr.length; i++){
            
            if( arr[i] < lar && arr[i] > sec ){
                sec = arr[i];
            }
            
        }
        
        
        return sec;
        
    }
}