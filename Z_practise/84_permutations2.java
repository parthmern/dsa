class Solution {

    public HashSet< List<Integer> > ans = new HashSet<>();
    
    public void helper(int arr[], int i){

        if( i>=arr.length ){
            List<Integer> temp = new ArrayList<>(Arrays.asList(arr))
            ans.add(temp);
            return;
        }

        for(int j=i; j<arr.length; j++){
            swap(arr, i ,j);
            helper(arr, i+1);
            swap(arr, i, j);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        helper(nums, 0);
        return new ArrayList<>(ans);
    }

    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}