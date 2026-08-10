/* Definition for Node
class Node
{
    int data;
    Node left;
    Node right;
    Node(int val)
    {
        this.data = val;
        left = null;
        right = null;
    }
}
*/

class Solution {
    
    ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    
    private void solve(Node root, ArrayList<Integer> temp){
        
        if(root == null) return;
        if(root.left == null && root.right == null){
            ArrayList<Integer> tmp = new ArrayList<>(temp);
            tmp.add(root.data);
            ans.add(tmp);
            return;
        }
        
        temp.add(root.data);
        
        if(root.left != null){
            solve(root.left, temp);
        }
        
        if(root.right != null){
           
            solve(root.right, temp);
           
        }
        temp.remove(temp.size()-1);
        
        
    }
    
    public ArrayList<ArrayList<Integer>> paths(Node root) {
        // code here
        
        solve(root, new ArrayList<>());
        
        return ans;
        
    }
}