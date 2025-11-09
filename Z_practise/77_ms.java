class Solution {
    
    
    void mergeTwoSortedArray(int arr[], int s, int e, int mid){
        
        // copy all values to arr1
        int[] left = new int[mid-s+1];
        int[] right = new int[e-mid];
        
        int k = s;
        for(int i=0; i<mid-s+1; i++){
            left[i] = arr[k++];
        }
        
        k = mid+1;
         for(int i=0; i<e-mid; i++){
            right[i] = arr[k++];
        }

        // left and right both are sorted you need to merge them
        int li = 0;
        int ri = 0;
        int idx = s;
        
        int len1 = mid-s+1;
        int len2 = e-mid;
        
        while( li < len1 && ri < len2 ){
            
            if( left[li] < right[ri] ){
                arr[idx++] = left[li++];
            }else{
                arr[idx++] = right[ri++];
            }
            
        }
        
        while(li<len1){
            arr[idx++] = left[li++];
        }
        
        while(ri<len2){
            arr[idx++] = right[ri++];
        }
        
    }
    
    
    void ms(int arr[], int s, int e){
        
        if(s>=e){
            return;
        }
        
        int mid = (s+e)/2;
        
        ms(arr, s, mid);
        ms(arr, mid+1, e);
        
        mergeTwoSortedArray(arr, s, e, mid);
    }

    void mergeSort(int arr[], int l, int r) {
        // code here
        ms(arr, l ,r);
        
    }
}