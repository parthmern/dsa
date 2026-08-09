/* Structure of binary tree node
class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}*/

class Pair{
    
    Node node;
    int l;
    Pair(Node root, int lvl){
        node = root;
        l = lvl;
    }
}

class Solution {
    
    TreeMap<Integer, ArrayList<Integer>> mp;
    
    Solution(){
        mp = new TreeMap<>();
    }
    
    private void solve(Node root){
        
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        //int level = 0;
        
        while(!q.isEmpty()){
            
            int w = q.size();
            for(int i=0; i<w; i++){
                Pair p = q.remove();
                Node front = p.node;
                int level = p.l;
                if(mp.get(level) == null){
                    mp.put(level, new ArrayList<>());
                }
                mp.get(level).add(front.data);
                
                if(front.left != null ) q.add(new Pair(front.left, level-1) );
                if(front.right != null ) q.add(new Pair(front.right, level+1) );
            }
            
            //level++;
        }
        
    }
    
    
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // code here
        solve(root);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        for(int key: mp.keySet()){
            ArrayList<Integer> temp = mp.get(key);
            ans.add(temp);
        }
        
        return ans;
        
        
    }
}