class Solution {
    
    private void heapify(int arr[], int size, int i){
        // i = parentIndex
        
        //System.out.println("arr we got" + Arrays.toString(arr));
        
        
        int left = 2*i+1;
        int right = 2*i+2;
        
        int largest = i;
        
        if( left <= size && arr[left] > arr[largest] ){
            largest = left;
        }
        
        if( right <= size && arr[right] > arr[largest] ){
            largest = right;
        }
        
        
        if(largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, size, largest);
        }
        
        
    }
    
    // Function to sort an array using Heap Sort.
    public void heapSort(int arr[]) {
        // code here
        
        // make heap
        
        for( int i=arr.length/2; i>=0; i-- ){
            heapify(arr, arr.length-1, i);
        }
        
        //System.out.println("after" + Arrays.toString(arr) ) ;
        
        for( int i=0; i<arr.length-1; i++){
            
            int lastIndex = arr.length - i - 1;
            
            int temp = arr[0];
            arr[0] = arr[lastIndex];
            arr[lastIndex] = temp;
            
            heapify(arr, lastIndex-1, 0);
            
            //System.out.println("hepify" + i + Arrays.toString(arr) ) ;
            
        }
        
    }
}