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

    int pIMain = 0;

    public TreeNode helper(int[] preorder, ArrayList<Integer> inorder, int is, int ie){

        if( pIMain >= preorder.length || is>ie ) return null;

        int pe = preorder[pIMain];
        pIMain++;
        int pos = inorder.indexOf(pe);

        TreeNode root = new TreeNode(pe);

        root.left = helper( preorder, inorder, is, pos-1 );
        root.right = helper(preorder, inorder, pos+1, ie);

        return root;

    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {

            ArrayList<Integer> inorderA = new ArrayList<>();
            for (int x : inorder) {
                inorderA.add(x);
            }


        return helper(preorder, inorderA , 0, inorder.length-1 );
        
    }
}