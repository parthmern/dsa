/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    List<List<Integer>> ans = new ArrayList<>();

     public void helper(TreeNode root, int ts, int sum, List<Integer> temp){

        System.out.println("sum now" + sum);

        if(root == null) return;

        System.out.println("here " + root.val +  " -----------");
        temp.add(root.val);

        if(root.left == null && root.right == null && sum + root.val == ts){
            ans.add(new ArrayList<>(temp));   
        
        }

        helper(root.left, ts, sum + root.val, temp);

        helper(root.right, ts, sum + root.val, temp);

        temp.remove(temp.size()-1);

        return;
 
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {

        ans.clear();

        helper(root, targetSum, 0, new ArrayList<>());

        return ans;

        
    }
}