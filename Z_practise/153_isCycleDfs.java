class Solution {
    
    private boolean dfs(Map<Integer, List<Integer> > adj, boolean[] isVisited, int node, int parent){
        
        isVisited[node] = true;
        
        List<Integer> neighbours = adj.get(node);
        if(neighbours == null) return false;
        
        for( int neigh : neighbours ){
            
            if( isVisited[neigh] && neigh != parent ) return true;
            
            if( !isVisited[neigh] ){
                boolean ans = dfs(adj, isVisited, neigh, node);
                if(ans) return true;
            }
            
        }
        
        return false;
        
    }
    
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        
        
        Map<Integer, List<Integer> > adj = new HashMap<>();
        
        for( int i=0; i<edges.length; i++ ){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj.computeIfAbsent( u, k-> new ArrayList<>() ).add(v);
            adj.computeIfAbsent( v, k-> new ArrayList<>() ).add(u);
            
        }
        
        boolean[] isVisited = new boolean[V];
        Arrays.fill(isVisited, false);
        
        for( int i=0; i<V; i++ ){
            int node = i;
            if( !isVisited[node] ){
                boolean ans = dfs(adj, isVisited, node, -1);
                if(ans) return true;
            }
           
        }
        
        return false;
        
        
    }
}