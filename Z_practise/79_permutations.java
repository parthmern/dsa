class Solution {

    private static List< List<Integer> > ans = new ArrayList<>();

    private void swap( int[] arr, int i, int j ){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void helper(int[] arr, int i){

        if( i>=arr.length ){
            List<Integer> temp= new ArrayList<>();
            for(int ele: arr){
                temp.add(ele);
            }
            // List<Integer> temp= new ArrayList<Integer>(Arrays.asList(arr));   
            // not work if Integer[] arr then works only
            ans.add(temp);
            return;
        }

        for( int j=i; j<arr.length; j++ ){
            swap(arr, i, j);
            helper(arr, i+1);
            swap(arr, i, j);
        }

    }

    public List<List<Integer>> permute(int[] nums) {
        ans.clear();    // due to static keyword
        helper(nums, 0);
        return ans;
    }
}