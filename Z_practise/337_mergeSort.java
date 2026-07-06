class Solution {
    
    private void mergeTwoSortedArr(int arr[], int s, int e){
        
        int mid = (s+e)/2;
        
        // make same temp arr
        int len = e-s+1;
        int[] temp = new int[len];
        
        int ti = 0;
        
        int i = s;
        int j = mid+1;
        
        while(i<=mid && j<=e){
            
            if(arr[i] <= arr[j]){
                temp[ti] = arr[i];
                i++;
            }else{
                temp[ti] = arr[j];
                j++;
            }
            
            ti++;
            
        }
        
        while(i<=mid){
            temp[ti] = arr[i];
            i++;
            ti++;
        }
        
        while(j<=e){
            temp[ti] = arr[j];
            j++;
            ti++;
        }
        
        // put all temp into real arr
        
        i = s;
        j = mid+1;
        ti = 0;
        
        while(i<=mid){
            arr[i] = temp[ti];
            ti++;
            i++;
        }
        
        while(j<=e){
            arr[j] = temp[ti];
            ti++;
            j++;
        }
        
    }
    
    
    
    private void ms(int arr[], int s, int e){
        
        if(s == e) return;
        
        int mid = (s+e)/2;
        
        ms(arr, s, mid);
        ms(arr, mid+1, e);
        
        mergeTwoSortedArr(arr, s, e);
        
    }
    
    public void mergeSort(int arr[], int l, int r) {
        // code here
        
        this.ms(arr, l, r);
        
    }
}