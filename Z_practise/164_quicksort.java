class Solution {
    public void quickSort(int[] arr, int low, int high) {
        // code here
        
        if(low>=high) return;
        
        int p = partition(arr, low, high);
        
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }

    private int partition(int[] arr, int low, int high) {
        
        // code here
        
        int s = low;
        int e = high;
        
        int PI = s;
        int PELE = arr[s];
        
        ArrayList<Integer> smaller = new ArrayList<>();
        
        ArrayList<Integer> bigger = new ArrayList<>();
        
        for(int i=s+1; i<=high; i++){
            if(arr[i] < PELE){
                smaller.add(arr[i]);
            }else{
                bigger.add(arr[i]);
            }
        }
        
        // put all smaller to left and bigger to  right
        
        int index = s;
        for(int i=0; i<smaller.size(); i++){
            arr[index++] = smaller.get(i);
        }
        
        PI = index;
        arr[index++] = PELE;
        
        
        for(int i=0; i<bigger.size(); i++){
            arr[index++] = bigger.get(i);
        }
        
        return PI;
        
    }
}