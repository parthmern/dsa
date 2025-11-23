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

    ArrayList<Integer> inorder = new ArrayList<>();

    public void helper(TreeNode root){
        if(root==null) return;
        helper(root.left);
        inorder.add( root.val );
        helper(root.right);
    }

    public boolean isSorted(){

        for(int i=0; i<inorder.size()-1; i++){
            if( inorder.get(i+1) > inorder.get(i) ){
                
            }else{
                return false;
            }
        }
        return true;
    }

    public boolean isValidBST(TreeNode root) {
        inorder.clear();
        helper(root);
        System.out.println(inorder);
        return isSorted();
    }
}