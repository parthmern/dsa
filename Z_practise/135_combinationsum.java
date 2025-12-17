class Solution {

    List<List<Integer>> ans = new ArrayList<>();

    private void helper(int[] arr, int target, int sum, List<Integer> temp, int index){

        if(sum>=target){
            if(sum==target) ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i=index; i<arr.length; i++){
            int ele = arr[i];
            temp.add(ele);
            helper(arr, target, sum+ele, temp, i);
            temp.remove(temp.size()-1); // bk
        }

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        ans.clear();
        List<Integer> temp = new ArrayList<>();
        
        helper(candidates, target, 0, temp, 0);

        return ans;
    }
}