// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution {
  public:
  
    void dfs(int node, int parent, unordered_map<int, list<int> > &adj, int timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &isVisited, vector<vector<int>> &result ){
        isVisited[node] = true;
        disc[node] = timer;
        low[node] = timer;
        timer = timer + 1;
        
        for(auto nbr: adj[node]){
            if(nbr == parent) continue;
            
            if(!isVisited[nbr]){
                dfs(nbr, node, adj, timer, disc, low, isVisited, result);
                low[node] = min(low[node], low[nbr]);
                // check edge is bridge 
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node); // node --- nbr
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                // backedge
                low[node] = min(low[node], disc[nbr]);
            }
            
        }
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        unordered_map<int, list<int> > adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        
        int parent = -1;
        unordered_map<int, bool> isVisited;
        
        vector< vector<int> > result;
        
        // dfs
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                dfs(i, parent, adj, timer, disc, low, isVisited, result);
            }
        }
        
         for (auto &p : result) {
            if ((p[0] == c && p[1] == d) ||
                (p[0] == d && p[1] == c)) {
                return true;
            }
        }

        return false;
        
    }
};class Solution {
  public:
  
    void dfs(int node, int parent, unordered_map<int, list<int> > &adj, int timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &isVisited, vector<vector<int>> &result ){
        isVisited[node] = true;
        disc[node] = timer;
        low[node] = timer;
        timer = timer + 1;
        
        for(auto nbr: adj[node]){
            if(nbr == parent) continue;
            
            if(!isVisited[nbr]){
                dfs(nbr, node, adj, timer, disc, low, isVisited, result);
                low[node] = min(low[node], low[nbr]);
                // check edge is bridge 
                if(low[nbr] > disc[node]){
                    vector<int> ans;
                    ans.push_back(node); // node --- nbr
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                // backedge
                low[node] = min(low[node], disc[nbr]);
            }
            
        }
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        unordered_map<int, list<int> > adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        
        int parent = -1;
        unordered_map<int, bool> isVisited;
        
        vector< vector<int> > result;
        
        // dfs
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                dfs(i, parent, adj, timer, disc, low, isVisited, result);
            }
        }
        
         for (auto &p : result) {
            if ((p[0] == c && p[1] == d) ||
                (p[0] == d && p[1] == c)) {
                return true;
            }
        }

        return false;
        
    }
};