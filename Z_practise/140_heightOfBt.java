/*
class Node {
    int data;
    Node left, right;

    Node(int val)
    {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    
    int ans = Integer.MIN_VALUE;
    
    private void helper(Node root, int h){
        
        if(root==null){
            ans = Math.max(ans, h-1);
            return;
        }
        
        helper(root.left, h+1);
        helper(root.right, h+1);
        return;
    }
    
    public int height(Node root) {
        // code here
        
        
        helper(root, 0);
        
        return ans;
        
    }
}