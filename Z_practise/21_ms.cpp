class Solution {
  public:
  
    void merging(vector<int>& arr ,int s, int e){
        
        int mid = (s+e)/2;
        
        // copy all vals into new arr
        int len1 = mid-s+1;
        int len2 = e-mid;
        int *arr1 = new int[len1];
        int *arr2 = new int[len2];
        
        for(int i=0; i<len1; i++){
            arr1[i] = arr[s+i];
        }
        
        for(int j=0; j<len2; j++){
            arr2[j] = arr[mid+1+j];
        }
        
        // merge two sorted arrays
        int leftIndex = 0;
        int rightIndex = 0;
        int mainIndex = s;
        
        while( leftIndex<len1 && rightIndex<len2 ){
            if(arr1[leftIndex] < arr2[rightIndex]){
                arr[mainIndex] = arr1[leftIndex];
                leftIndex++;
                mainIndex++;
            }else{
                arr[mainIndex] = arr2[rightIndex];
                rightIndex++;
                mainIndex++;
            }
        }
        
        while(leftIndex<len1){
             arr[mainIndex] = arr1[leftIndex];
                leftIndex++;
                mainIndex++;
        }
        
        while(rightIndex<len2){
             arr[mainIndex] = arr2[rightIndex];
                rightIndex++;
                mainIndex++;
        }
        
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        
        int s = l;
        int e = r;
        int mid = (s+e)/2; 
        
        if(s>=e) return;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merging(arr,s,e);
        
        
    }
};