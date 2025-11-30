// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


class Solution {
  public:
  
    bool isCycleBFS(int srcNode, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &isVisited,  unordered_map<int, int> &parent){
        parent[srcNode] = -1;
        isVisited[srcNode] = true;
        
        queue<int> q;
        q.push(srcNode);
        
        while( !q.empty() ){
            int front = q.front();
            q.pop();
            
            for(auto neighbour: adj[front]){
                
                // If neighbor visited and not parent, cycle exists
                if( isVisited[neighbour] && (neighbour != parent[front]) ) return true;
                
                if( !isVisited[neighbour] ){
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                    parent[neighbour] = front;
                }
                
            }
        }
        
    }
    
    bool isCycleDFS(int srcNode, int parent, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &isVisited){
        isVisited[srcNode] = true;
        
        for(auto neighbour: adj[srcNode]){
            if(isVisited[neighbour] && neighbour != parent) return true;
            
            if( !isVisited[neighbour]){
                
                if(isCycleDFS(neighbour, srcNode, adj, isVisited)) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        unordered_map<int, int> parent;
        unordered_map<int, bool> isVisited;
        
        unordered_map<int, list<int> > adj; 
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                //bool ans = isCycleBFS(i, adj, isVisited, parent);
                bool ans = isCycleDFS(i, -1, adj, isVisited);
                if(ans == true) return true;
            }
        }
        
        return false;
    }
};