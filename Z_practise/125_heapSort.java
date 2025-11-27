class Solution {
    // Function to sort an array using Heap Sort.
    
    public void heapify(int[] arr, int size, int i){
        
        int largestIndex = i;
        
        int childOneIndex = 2 * i +1;
        int childTwoIndex = 2 * i +2;
        
        if( childOneIndex<size && arr[childOneIndex] > arr[largestIndex] ){
            largestIndex = childOneIndex;
        }
        
         if( childTwoIndex<size && arr[childTwoIndex] > arr[largestIndex] ){
            largestIndex = childTwoIndex;
        }
        
        if(largestIndex != i){
            swap(arr, largestIndex, i);
            heapify(arr, size, largestIndex);
        }
        
    }
    
    
     private void swap(int[] harr, int i, int j) {
        int temp = harr[i];
        harr[i] = harr[j];
        harr[j] = temp;
    }
    
    public void heapSort(int arr[]) {
        // code here
        
        int n = arr.length;
        for (int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);


        
       for (int i = n - 1; i >= 0; i--) {
            swap(arr, 0, i);     
            heapify(arr, i, 0);
        }

        
    }
}