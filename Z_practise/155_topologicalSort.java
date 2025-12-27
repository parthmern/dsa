class Solution {
    
    private void dfs(int node, Map<Integer, List<Integer> > adj, Stack<Integer> st, boolean[] isVisited){
        
        isVisited[node] = true;
        
        List<Integer> nbrs = adj.get(node);
        if(nbrs == null){
            st.add(node);
            return;
        }
        
        for( int nbr: nbrs ){
            if(!isVisited[nbr]){
                dfs(nbr, adj, st, isVisited);
            }
        }
        
        // after all add into stack
        st.add(node);
    }
    
    public ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        
        Map<Integer, List<Integer>> adj = new HashMap<>();
        
        for(int[]edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k-> new ArrayList<>()).add(v);
        }
        
        Stack<Integer> st = new Stack<>();
        
        boolean[] isVisited = new boolean[V];
        Arrays.fill(isVisited, false);
        
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                dfs(i, adj, st, isVisited);
            }
        }
        
        // System.out.println(st);
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        while(!st.empty()){
            int temp = st.pop();
            ans.add(temp);
        }
        
        return ans;
        
    }
}