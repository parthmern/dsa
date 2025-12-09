// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution {
public:

    void dfs1(int node, vector<vector<int>> &adj,
              unordered_map<int, bool> &vis1, stack<int> &st){
        
        vis1[node] = true;

        for(int nbr : adj[node]){
            if(!vis1[nbr]){
                dfs1(nbr, adj, vis1, st);
            }
        }

        st.push(node);  // finishing time
    }

    void dfs2(int node, vector<vector<int>> &transpose,
              unordered_map<int, bool> &vis2){
        
        vis2[node] = true;

        for(int nbr : transpose[node]){
            if(!vis2[nbr]){
                dfs2(nbr, transpose, vis2);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();

        unordered_map<int, bool> vis1, vis2;
        stack<int> st;

        // Step 1: Topological Sort (DFS1)
        for(int i = 0; i < V; i++){
            if(!vis1[i]){
                dfs1(i, adj, vis1, st);
            }
        }

        // Step 2: Create Transpose graph
        vector<vector<int>> transpose(V);
        for(int u = 0; u < V; u++){
            for(int v : adj[u]){
                transpose[v].push_back(u);
            }
        }

        int sccCount = 0;

        // Step 3: Process stack & DFS2 on transpose
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis2[node]){
                sccCount++;
                dfs2(node, transpose, vis2);
            }
        }

        return sccCount;
    }
};
