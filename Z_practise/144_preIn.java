/*
class Node {
    int data;
    Node left, right;
    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/

class Solution {
    
    
    // LNR
    private void inorder(Node root, ArrayList<Node> ans){
        if(root==null) return;
        inorder(root.left, ans);
        ans.add(root);
        inorder(root.right, ans);
    }
    
    public ArrayList<Node> findPreSuc(Node root, int key) {
        // code here
        
        ArrayList<Node> ans = new ArrayList<>();
        inorder(root, ans);
        
        //System.out.println(ans);
        
        ans.forEach( node -> System.out.print(node.data +" "));
        
        Node pre = new Node(-1);
        Node suc = new Node(-1);
        
        if( key == ans.get(0).data ){
            //pre = ans.get(i-1);
            suc = ans.get(1);
        }
        
        else if(key == ans.get(ans.size()-1).data ){
            pre = ans.get(ans.size()-2);
            // suc = ans.get(1);
        }
        
        else{
             for(int i=1; i<ans.size()-1; i++){
            
            if( key == ans.get(i).data ){
                pre = ans.get(i-1);
                suc = ans.get(i+1);
                break;
            }
            
            if( ( ans.get(i).data < key && ans.get(i+1).data > key )){
                pre = ans.get(i);
                suc = ans.get(i+1);
                break;
            }    
            
        }
        }
        
       
        return new ArrayList<>(List.of(pre, suc));
    
    }
}