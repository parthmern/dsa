class Solution {
    
    private void mergeTwoSortedArr(int[] arr, int s, int e){
        
        int mid = (s+e)/2;
        
        int len1 = mid-s+1;
        int len2 = e-mid;
        
        int[] arr1 = new int[len1];
        int[] arr2 = new int[len2];
        
        int index = s;
        for(int i=0; i<len1; i++){
            arr1[i] = arr[index++];
        }
        
        for(int j=0; j<len2; j++){
            arr2[j] = arr[index++];
        }
        
        //System.out.println(Arrays.toString(arr1) + " " + Arrays.toString(arr2));

        
        // merge 2 sorted arr
        int i = 0;
        int j = 0;
        
        index = s;
        
        while(i<len1 && j<len2){
            if(arr1[i]<arr2[j]){
                arr[index++] = arr1[i++];
            }else{
                arr[index++] = arr2[j++];
            }
        }
        
        while(i<len1){
            arr[index++] = arr1[i++];
        }
        
        while(j<len2){
            arr[index++] = arr2[j++];
        }
        
        //System.out.println("=>" + Arrays.toString(arr));

        
    }

    void mergeSort(int arr[], int l, int r) {
        // code here
        
        int s = l;
        int e = r;
        
        if(s>=e) return;
        
        int mid = (s+e)/2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        mergeTwoSortedArr(arr, s, e);
        
    }
}

// n log n