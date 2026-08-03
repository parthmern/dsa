class Solution {
    
    private void swap(int arr[], int i, int j){
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
    }
    
    private void heapify(int arr[], int n, int pi){
    

        while(pi>=0 && pi<n){
            
            int childL = 2*pi + 1;
            int childR = 2*pi + 2;
            
            int smallestI = pi;
            
            if(childL < n && arr[smallestI] < arr[childL]){
                smallestI = childL;
            }
            
            if(childR < n && arr[smallestI] < arr[childR]){
                smallestI = childR;
            }
            
            if(smallestI == pi) break;
            
            swap(arr, pi, smallestI);
            pi = smallestI;
            
        }
        
        
    }
    
    // Function to sort an array using Heap Sort.
    public void heapSort(int arr[]) {
        // code here
        
        int n = arr.length;
        
        
        //System.out.println("i s=> " + n/2);
        
        // all leaf nodes are already heap prop follow
        for(int i=n/2; i>=0; i--){
            heapify(arr, n, i);
            
        }
        //System.out.println("after i => "  + " " + Arrays.toString(arr));
        
        // heapsort
        // [9, 7, 3, 1, 4]
        
        int index = 0;
        
        for(int i=n-1; i>=0; i--){
            
            swap(arr, 0, i);
            heapify(arr, i, 0);
            
            //System.out.print("after i => " + i + " " + Arrays.toString(arr) + "    ");
            
        }
        
        
        
    }
}