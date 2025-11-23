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

    TreeNode ans = null;

    public void helper(TreeNode root, int val){

        if(root==null) return;

        if(root.val == val){
            ans = root;
            return;
        }

        if( root.val > val ){
            // 10 > 5
            helper(root.left, val);
        }else{
            helper(root.right, val);
        }

    }

    public TreeNode searchBST(TreeNode root, int val) {
        helper(root, val);
        return ans;
    }
       
}