/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/


class Pair{
    Node node;
    int count;
    
    Pair(Node n, int lvl){
        this.node = n;
        this.count = lvl;
    }
}

class Solution {
    
    private void bfs(Map<Integer, ArrayList<Integer> > mp, Queue<Pair> q){
        
        while(!q.isEmpty()){
            
            Pair ele = q.remove();
            mp.computeIfAbsent(ele.count, k -> new ArrayList<>()).add(ele.node.data);
            
            if(ele.node.left != null){
                q.add(new Pair(ele.node.left, ele.count-1) );
            }
            
            if(ele.node.right != null){
                q.add(new Pair(ele.node.right, ele.count+1) );
            }
            
        }
        
    }
    
    
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // code here
        
        Map<Integer, ArrayList<Integer> > mp = new TreeMap<>();
        
        Queue<Pair> q = new LinkedList<>();
        
        Pair temp = new Pair(root, 0);
        
        q.add(temp);
        
        bfs(mp, q);
                                // sorted based on Keys
        System.out.println(mp); // {-2=[4], -1=[2], 0=[1, 5], 1=[3], 2=[6]}
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        for(Integer key : mp.keySet() ){
            ans.add( mp.get(key) );
        }
        
        return ans;
        
        
    }
}