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

    private int maxDepth(TreeNode root) {
        if(root == null) return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    private boolean isBal(int lh, int rh){
        int ans = 0;
        if(lh>=rh){
            ans = lh-rh;
        }else{
            ans = rh-lh;
        }
        if(ans>1) return false;
        return true;
    }

    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        boolean rootAns = isBal(maxDepth(root.left), maxDepth(root.right));
        boolean leftAns = isBalanced(root.left);
        boolean rightAns = isBalanced(root.right);
        return rootAns && leftAns && rightAns;
    }
}