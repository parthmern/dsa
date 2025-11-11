class Solution {


    public List<List<Integer>> ans = new ArrayList<>();

    public void helper(int[] arr, int target, int i, int sum, List<Integer> temp){

        if( sum >= target ){
            if(sum == target){
                ans.add(new ArrayList<>(temp));
            }
            return;
        }

        for( int j=i; j<arr.length; j++ ){
            if (j > i && arr[j] == arr[j - 1]) continue;
            temp.add(arr[j]);
            helper(arr, target, j+1, sum + arr[j], temp);
            temp.remove(temp.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        helper(candidates, target, 0, 0, new ArrayList<>());
        return ans;
    }
}