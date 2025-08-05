class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
    
        
        for( int i=0; i<arr.size()-1; i++ ){
            
            int smallestIndex = i;
            for(int j = i+1; j<arr.size(); j++){
                if( arr[j] < arr[smallestIndex] ){
                    smallestIndex = j;
                }
            }
            
            swap(arr[i], arr[smallestIndex]);
            
        }
        
        
    }
};