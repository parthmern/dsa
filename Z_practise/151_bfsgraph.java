class Solution {
    
    private void bfs( ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> ans, boolean[] isVisited, Queue<Integer> q, int vertices){
        
        while( !q.isEmpty() ){
            
            int ele = q.remove();
            
            ans.add(ele);
            
            
                for(int node: adj.get(ele)){
                    if( !isVisited[node] ){
                         q.add(node);
                        isVisited[node] = true;
                    }
                   
                }
            
            
        }
        
        
    }
    
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        boolean[] isVisited = new boolean[adj.size()];
        Arrays.fill(isVisited, false);
        
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=0; i<adj.size(); i++){
            //i = node
            if( !isVisited[i] ){
                q.add(i);
                isVisited[i] = true;
                bfs(adj, ans, isVisited, q, i);       
            }
        }
        
        return ans;
        
        
    }
}