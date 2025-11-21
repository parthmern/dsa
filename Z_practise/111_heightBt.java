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

    public int helper(TreeNode root, int h){

        if(root==null) return h;

        int leftH = helper(root.left, h+1);
        int rightH = helper(root.right, h+1);

        return Math.max(leftH, rightH);

    }

    public int maxDepth(TreeNode root) {

        return helper(root, 0);
        
    }
}