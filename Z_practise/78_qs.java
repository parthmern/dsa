class Solution {
    public void quickSort(int[] arr, int low, int high) {
        if( low >= high ){
            return ;
        }
        
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
        
    }

    private int partition(int[] arr, int low, int high) {
        
        int p = low;
        int pEle = arr[p];
        
        int count = 0;

        
        for( int i=low+1; i<=high ; i++ ){
            if( arr[i] < pEle ){
                count++;
            }
        }
        
        int right = low + count;

        
        //swap
        int temp = arr[right];
        arr[right] = arr[low];
        arr[low] = temp;

        p = right; // pivot index updated
        pEle = arr[p];

        
        int[] leftArr = new int[p-low];
        int[] rightArr = new int[high-p];
             
        int leftI = 0;
        int rightI = 0;
        
        for(int i=low; i<= high; i++){
            
            if( i == p ){
                continue;
            }
            
            if( arr[i] < pEle ){
                leftArr[leftI++] = arr[i];
            }else{
                rightArr[rightI++] = arr[i];
            }
            
        }
        
        int idx = low;
        for(int i=0; i<leftI; i++){
            arr[idx++] = leftArr[i];
        }
        
        arr[idx++] = pEle;
        for(int i=0; i<rightI; i++){
            arr[idx++] = rightArr[i];
        }
        
        
        return p;
        
    }
}