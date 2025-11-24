/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {

    ArrayList<TreeNode> pa = new ArrayList<>();
    ArrayList<TreeNode> qa = new ArrayList<>();

    public void store(TreeNode root, TreeNode target, ArrayList<TreeNode> temp ){

        if( root == null ) return;

        temp.add(root);

        if(root == target) return; 

        if(root.val > target.val){
            store(root.left, target, temp);
        }else{
            store(root.right, target, temp);
        }

        return;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        store(root, p, pa);
        store(root, q, qa);

        for(TreeNode ele: pa) System.out.print(ele.val + " ");
        System.out.println("--");
        for(TreeNode ele: qa) System.out.print(ele.val + " ");

        int lenPa = pa.size();
        int lenQa = qa.size();

        int i =0 ;

        while(i < lenPa-1 && i< lenQa-1){
            if( pa.get(i+1) != qa.get(i+1) ) return pa.get(i);
            i++;
        }

        return pa.get(Math.min(lenPa, lenQa) - 1);

    }
}