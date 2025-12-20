
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
    
    void helper(Node root, Map<Integer, List<Integer> > mp){
        
        if(root==null) return;
        
        List<Integer> childs = mp.get(root.data);
        
        if (childs == null) return;

        if (childs.size() > 0) {
            root.left = new Node(childs.get(0));
            helper(root.left, mp);
        }
    
        if (childs.size() > 1) {
            root.right = new Node(childs.get(1));
            helper(root.right, mp);
        }

    }
    
    Node createTree(int[] parent) {
        // code here
        
        Map<Integer, List<Integer> > mp = new HashMap<>();
        
        for(int i=0; i<parent.length; i++){
            
            Integer ele = Integer.valueOf(i);
            Integer par = Integer.valueOf(parent[i]);
            
            if( mp.get(par) == null ){
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(ele);
                mp.put(par, temp);
            }else{
                mp.get(par).add(ele);
            }
            
        }
        
        // System.out.println(mp);
        
        
        Node root = new Node(mp.get(-1).get(0));
        
        helper(root, mp);
        
        return root;
    }
}
