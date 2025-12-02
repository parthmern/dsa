// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list (node -> list of {neighbor, weight})
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // Step 2: Topological Sort using DFS
        vector<bool> visited(V, false);
        stack<int> st;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto &p : adj[node]) {
                int nbr = p.first;
                if (!visited[nbr]) dfs(nbr);
            }
            st.push(node);
        };

        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i);
        }

        // Step 3: Distance array
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;   // src = 0

        // Step 4: Process nodes in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX) {
                for (auto &p : adj[node]) {
                    int nbr = p.first;
                    int wt = p.second;

                    if (dist[node] + wt < dist[nbr]) {
                        dist[nbr] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable nodes (INT_MAX → -1)
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
