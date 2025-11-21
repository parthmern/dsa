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



    public boolean isBalanced(TreeNode root) {

        if(root==null) return true;

        int lh = helper(root.left, 0);
        int rh = helper(root.right, 0);

        int diff = Math.abs(lh - rh);

        if( !(diff <= 1) ) return false;

        boolean la = isBalanced(root.left);
        boolean ra = isBalanced(root.right);

        return la && ra ;

        
    }
}