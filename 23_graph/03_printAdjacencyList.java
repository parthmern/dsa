// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

class Solution {
    public List<List<Integer>> printGraph(int V, int edges[][]) {
        
        List<List<Integer>> ans = new ArrayList<>();
        
        for(int i=0; i<V; i++){
            ans.add( new ArrayList<>() );
        }
        
        for(int i=0; i<edges.length; i++){
            for(int j=0; j<edges[0].length; j++){
                int u = edges[i][0];
                int v = edges[i][1];

                ans.get(u).add(v);  // u -- v
                ans.get(v).add(u);  // v -- u (because undirected)
            }
        }
        
        return ans;
        
    }
}