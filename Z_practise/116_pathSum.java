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

    public boolean helper(TreeNode root, int ts, int sum){

        System.out.println("sum now" + sum);

        if(root == null) return false;

        System.out.println("here " + root.val +  " -----------");

        if(root.left == null && root.right == null && sum + root.val == ts) return true;

        return helper(root.left, ts, sum + root.val) || helper(root.right, ts, sum + root.val);
 
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        return helper(root, targetSum, 0);
    }
}