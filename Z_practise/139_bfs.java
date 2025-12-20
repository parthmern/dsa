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

    List< List<Integer> > ans = new ArrayList<>();

    private void bfs(Queue<TreeNode> q ){

        List<Integer> temp = new ArrayList<>();

        while(!q.isEmpty()){

            TreeNode ele = q.remove();

            if(ele==null){
                ans.add(new ArrayList<>(temp));
                temp.clear();
                if(q.size()>=1)q.add(null);
                
            }else{
                temp.add(ele.val);
                if(ele.left != null) q.add(ele.left);
                if(ele.right !=null) q.add(ele.right); 
            }

        }

    }

    public List<List<Integer>> levelOrder(TreeNode root) {

        if(root == null) return ans;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        bfs(q);

        return ans;
        
    }
}