class Solution {
    
    private void helper(ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> ans, boolean[] isVisited, int node){
        isVisited[node] = true;
        ans.add(node);
        
        for( int ele: adj.get(node) ){
            if(!isVisited[ele]) helper(adj, ans, isVisited, ele);
        }
        
    }
    
    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] isVisited = new boolean[adj.size()];
        Arrays.fill(isVisited, false);
        
        for(int i=0; i<adj.size(); i++){
            if(!isVisited[i]) helper(adj, ans, isVisited, i);
        }
        
        return ans;
        
        
    }
}