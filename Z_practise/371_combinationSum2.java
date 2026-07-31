class Solution {

    List<List<Integer>> ans = new ArrayList<>();

    private void solve(int[] arr, int target, int i, int sum, ArrayList<Integer> temp){
        if(sum==target){
            ans.add(new ArrayList<>(temp));
            return;
        }

        if(i>=arr.length || sum>target) return;

        // include
        temp.add(arr[i]);
        solve(arr, target, i+1, sum+arr[i], temp);
        temp.remove(temp.size()-1);

        // exclude
        while(i+1<arr.length && arr[i] == arr[i+1]) i++;
        solve(arr, target, i+1, sum, temp);
            
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        solve(candidates, target, 0,0,new ArrayList<>());
        return ans;
    }
}