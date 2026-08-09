/* Structure of Binary Tree Node
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = this.right = null;
    }
}*/

class Solution {
    
    ArrayList<Integer> ans = new ArrayList<>();
    
    private void solve(Node root, int lvl){
        if(root==null) return;
        if(ans.size()==lvl) ans.add(root.data);
        solve(root.left, lvl+1);
        solve(root.right, lvl+1);
    }
    
    public ArrayList<Integer> leftView(Node root) {
        ans.clear();
        solve(root, 0);
        return ans;
    }
}