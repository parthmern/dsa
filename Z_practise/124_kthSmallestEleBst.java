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

    int k = 0;
    int ans;

    public void helper(TreeNode root, int target){
        if(root==null) return;

        helper(root.left, target);  // L
        k++;    // N
        if(k==target) ans = root.val;
        helper(root.right, target);

        return;
    }

    public int kthSmallest(TreeNode root, int k) {

        helper(root, k);
        return ans;
        
    }
}