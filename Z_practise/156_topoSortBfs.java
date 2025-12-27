class Solution {
    public ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        
        Map<Integer, ArrayList<Integer>> adj = new HashMap<>();
        
        for(int[]edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k-> new ArrayList<>()).add(v);
        }
        
        int[] inorder = new int[V];
        Arrays.fill(inorder, 0);
        
        for(int key : adj.keySet()){
            ArrayList<Integer> nbrs = adj.get(key);
            for(int node: nbrs){
                inorder[node] = inorder[node] + 1;
            }
        }
        
        // in q add all 0 indegs
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=0; i<inorder.length; i++){
            if(inorder[i] == 0){
                q.add(i);
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        while(!q.isEmpty()){
            int front = q.remove();
            ans.add(front);
            
            ArrayList<Integer> nbrs = adj.get(front);
            if(nbrs == null) continue;
            
            for(int nbr: nbrs){
                inorder[nbr] = inorder[nbr] - 1;
                if(inorder[nbr] == 0){
                    q.add(nbr);
                }
            }
            
        }
        
        return ans;
        
    }
}