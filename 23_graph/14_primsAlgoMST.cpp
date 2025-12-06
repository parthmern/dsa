// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        // start from node 0 
        key[0] = 0;
        parent[0] = -1;

        
        for(int i = 0; i < V - 1; i++) {

            int mini = INT_MAX;
            int u = -1;

           
            for(int v = 0; v < V; v++) {
                if(mst[v] == false && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            mst[u] = true;  // include this node in MST

            // update neighbors
            for(auto p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if(mst[v] == false && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        // -------- calculate MST total weight --------
        int sum = 0;
        for(int i = 0; i < V; i++) {
            sum += key[i];
        }

        return sum;
    }
};
