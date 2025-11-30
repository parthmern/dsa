// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


class Solution {
  public:
    
    bool checkCycleDFS( int node, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &dfsVisited, unordered_map<int, bool> &isVisited){
        
        isVisited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neighbour : adj[node]){
            
            if( !isVisited[neighbour] ){
                bool ans = checkCycleDFS(neighbour, adj, dfsVisited, isVisited);
                if(ans) return true;
            } else if( isVisited[neighbour] && dfsVisited[neighbour] ){
                return true;
            }
            
        }
        
        dfsVisited[node] = false;
        return false;
        
    }
    
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        unordered_map<int, bool> isVisited;
        unordered_map<int, bool> dfsVisited;
        unordered_map<int, list<int> > adj;
        for(int i=0; i<edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v); // u --> v
            
        }
        
        for(int i=0; i<edges.size(); i++){
            if( !isVisited[i] ){
                bool ans = checkCycleDFS(i, adj, dfsVisited, isVisited);
                if(ans) return true;
            }   
        }
        
        return false;
        
        
    }
};