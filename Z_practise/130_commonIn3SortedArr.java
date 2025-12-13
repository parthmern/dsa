// User function Template for Java

class Solution {
    // Function to find common elements in three arrays.
    public List<Integer> commonElements(List<Integer> arr1, List<Integer> arr2,
                                        List<Integer> arr3) {
        // Code Here
        
        
        int i = 0;
        int j = 0; 
        int k = 0;
        
        List<Integer> ans = new ArrayList<>();
        
        
        while( i<arr1.size() && j < arr2.size() && k < arr3.size() ){
            
            if (arr1.get(i).equals(arr2.get(j)) && arr2.get(j).equals(arr3.get(k))) {
                if(!ans.contains(arr1.get(i))){
                    ans.add(arr1.get(i));
                }
                i++;
                j++;
                k++;
                continue;
            }
            
            if( arr1.get(i) < arr2.get(j) ) i++;
            else if( arr2.get(j) < arr3.get(k) ) j++;
            else if( arr3.get(k) < arr1.get(i) ) k++;
            else {
                i++;
                j++;
                k++;
            }
        }
        
        return ans;
        
    
        
    }
}