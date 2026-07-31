class Solution {

    List<List<Integer>> ans = new ArrayList<>();

    private void solve(int[] arr, int target, int i, int sum, ArrayList<Integer> temp){

        if(i>=arr.length || sum>target) return;

        if(sum==target){
            ans.add(new ArrayList<>(temp));
            return;
        }

        // include
        temp.add(arr[i]);
        solve(arr, target, i, sum+arr[i], temp);
        temp.remove(temp.size()-1);

        // exclude
        solve(arr, target, i+1, sum, temp);
            
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        solve(candidates, target, 0,0,new ArrayList<>());
        return ans;
    }
}