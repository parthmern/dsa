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

    private int height(TreeNode root){
        if(root == null) return 0;
        if(root.left == null && root.right == null) return root.val;
        int left = root.left != null ? Math.max(0, height(root.left)) : 0;
        int right = root.right != null ? Math.max(0, height(root.right)) : 0;
        return root.val + Math.max(left, right);

    }

    private int solve(TreeNode root){

        if(root == null) return Integer.MIN_VALUE;
        if(root.left == null && root.right == null) return root.val;
        int h = root.val
            + (root.left != null ? Math.max(0, height(root.left)) : 0)
            + (root.right != null ? Math.max(0, height(root.right)) : 0);
        int lh = root.left != null ? solve(root.left) : Integer.MIN_VALUE;
        int rh = root.right != null ? solve(root.right) : Integer.MIN_VALUE;
        return Math.max(root.val, Math.max(h, Math.max(lh, rh)));
    }

    public int maxPathSum(TreeNode root) {
        return solve(root);
    }
}