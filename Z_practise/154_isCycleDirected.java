class Solution {
    
    private boolean dfs(int node, Map<Integer, List<Integer>> adj, boolean[] isVisited, boolean[] isDfsVisited){
        
        List<Integer> nbrs = adj.get(node);
        if(nbrs==null) return false;
        
        for( int nbr : nbrs ){
            
            if( isVisited[nbr] && isDfsVisited[nbr] ){
                //System.out.println("for"+ nbr);
                return true;
            }
            
            if( !isVisited[nbr] ){
                isVisited[nbr] = true;
                isDfsVisited[nbr] = true;
                if( dfs(nbr, adj, isVisited, isDfsVisited) ){
                    //System.out.println("for"+ nbr);
                    return true;
                }
                isDfsVisited[nbr] = false;
            }
        }
        
        return false;
    }
    
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        
        boolean[] isVisited = new boolean[V];
        Arrays.fill(isVisited, false);
        boolean[] isDfsVisited = new boolean[V];
        Arrays.fill(isDfsVisited, false);
        
        Map<Integer, List<Integer>> adj = new HashMap<>();

        
        for( int[] edge: edges ){
            int u = edge[0];
            int v = edge[1];
            // u -> v
            
            adj.computeIfAbsent(u, k-> new ArrayList<>()).add(v);
        }
        
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                isVisited[i] = true;
                isDfsVisited[i] = true;
                if( dfs(i, adj, isVisited, isDfsVisited) ){
                    //System.out.println("for ma"+ i);
                    return true;
                }
                isDfsVisited[i] = false;
            }
        }
        
        return false;
        
    }
}