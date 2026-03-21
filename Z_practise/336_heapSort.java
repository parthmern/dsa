class Solution {
    // Function to sort an array using Heap Sort.
    
    private void heapify(int arr[], int s, int i){
        
        while(i<s){
            
            int parentI = i ;
            
            int left = (2*i) + 1;
            int right = (2*i) + 2;
            
            if( left < s && arr[left] > arr[parentI] ) parentI = left;
            if( right < s && arr[right] > arr[parentI] ) parentI = right;
            
            if(parentI == i) break;
            
            int temp = arr[parentI];
            arr[parentI] = arr[i];
            arr[i] = temp;
            
            i = parentI;
            
        }
        
        
    }
    
    public void heapSort(int arr[]) {
        // code here
        
        int n = arr.length;
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }
        
        // int i = n-1;
        while(n>0){
            
            // swap with last ele
            int temp = arr[0];
            arr[0] = arr[n-1];
            arr[n-1] = temp;
            
            n--;
            
            heapify(arr, n ,0);
                         
            
        }
        
    }
}