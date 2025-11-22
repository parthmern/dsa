/* Node is defined as
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}*/
class Tree {
    
    HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();    
    
    int maxi = Integer.MIN_VALUE;
    
    public void helper(Node root, int i){
            
        if(root==null) return;
        
        maxi = Math.max( maxi, i );
        
        if( map.get(i) == null ){
            ArrayList<Integer> t = new ArrayList<>();
            t.add(root.data);
            map.put( i, t );
        }else{
            map.get(i).add(root.data);
        }
        
        helper( root.left , i+1 );
        helper( root.right, i);
        
    }
    
    public ArrayList<Integer> diagonal(Node root) {
        // add your code here.
        
        helper(root, 0);
        
       // System.out.println("s" + map);
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0; i<=maxi; i++){
            
            ArrayList<Integer> temp = map.get(i);
            
            for( Integer ele: temp ){
                ans.add(ele);
            }
            
        }
    
        return ans;
    }
}