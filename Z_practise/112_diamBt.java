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

    

    public int height(TreeNode root, int h){

        if(root==null) return h;

        int leftH = height(root.left, h+1);
        int rightH = height(root.right, h+1);

        return Math.max(leftH, rightH);

    }

    public int helper(TreeNode root){

        if(root==null) return 0;

        int dl = helper(root.left);
        int dr = helper(root.right);

        int h = height(root.left, 0) + height(root.right, 0)  ;

        return Math.max(dl, Math.max(dr, h));

    }


    public int diameterOfBinaryTree(TreeNode root) {
        if(root.left==null && root.right==null) return 0;

        return helper(root)  ;
        
    }
}