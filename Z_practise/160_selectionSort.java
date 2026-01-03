class Solution {
    void selectionSort(int[] arr) {
        // code here
        
        for(int i=0; i<arr.length; i++){
            
            int smallestIndex = i;
            for(int j=i+1; j<arr.length; j++){
                if(arr[smallestIndex] > arr[j]) smallestIndex = j;
            }
            
            if(smallestIndex != i){
                int temp = arr[i];
                arr[i] = arr[smallestIndex];
                arr[smallestIndex] = temp;
            }
            
        
        }
        
    }
}