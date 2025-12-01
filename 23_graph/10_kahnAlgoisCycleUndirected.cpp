class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);   // Undirected
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Push all leaf nodes (degree == 1)
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int count = 0;  // number of nodes removed

        // Remove leaves one-by-one
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;   // we removed this node

            for (int neigh : adj[node]) {
                degree[neigh]--;

                // If neighbour becomes a leaf, push it
                if (degree[neigh] == 1)
                    q.push(neigh);
            }
        }

        // If count == V → all nodes removed → NO cycle
        // If count < V → nodes remain → CYCLE
        return count != V;
    }
};
