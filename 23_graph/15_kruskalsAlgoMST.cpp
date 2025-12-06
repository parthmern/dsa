// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

class Solution {
  public:
    
    void makeSet(vector<int> &parent, vector<int> &rank, int n){
        
        for(int i=0; i<n; i++){
            parent[i] = i;  // initially ele khud ka parent hoga
            rank[i] = 0;    // initially sab ki rank 0 hpgi
        }
        
    }
    
    
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node) return node;
        int ans = findParent(parent, parent[node]);
        parent[node] = ans; // path compression
        return ans;
    }
    
    void unionSet(vector<int> &parent, vector<int> &rank, int u, int v){
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[v] < rank[u]){
            parent[v] = u;
        }else{ // both same
            parent[v] = u;
            rank[u]++;
        }
    }
    
    // inside of class so static  | not datatype type
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        sort(edges.begin(), edges.end(), cmp);
        vector<int> parent(V);
        vector<int> rank(V);
        
        makeSet(parent, rank, V);
        
        int minWeight = 0;
        
        for(int i=0; i<edges.size(); i++){
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int w = edges[i][2];
            
            if(u != v){ // not in same tree
                minWeight = minWeight + w;
                unionSet(parent, rank, u, v);
            }
        }
        
        return minWeight;
        
    }
};