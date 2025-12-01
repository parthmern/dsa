// https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
public:

    void dfs(int node, unordered_map<int, list<int>>& adj, 
             unordered_map<int, bool>& visited, stack<int>& st) 
    {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, st);
            }
        }

        // push the node to stack after visiting all neighbours
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: build adjacency list
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);  // u -> v
        }

        // Step 2: DFS + stack
        unordered_map<int, bool> visited;
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Step 3: pop nodes from stack to get topo order
        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
        }

        return topoOrder;
    }
};
