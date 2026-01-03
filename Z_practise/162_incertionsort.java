class Solution {
    // Please change the array in-place
    
    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    public void insertionSort(int arr[]) {
        // code here
        
        for(int i=0; i<arr.length; i++){
            int b = i;
            int a = i-1;
            
            while(a>=0){
                 if(arr[a] > arr[b]){
                    //System.out.println("b" + b);
                    swap(arr, a, b);
                }
                a--;
                b--;     
            }
        }
        
    }
}