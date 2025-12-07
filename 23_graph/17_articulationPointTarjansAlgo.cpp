// https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution {
public:
    void dfs(int u, int parent, unordered_map<int, list<int>> &adj,
             vector<int> &disc, vector<int> &low, vector<bool> &visited,
             vector<int> &ap, int &timer) {

        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, ap, timer);

                low[u] = min(low[u], low[v]);

                // Check if u is an articulation point
                if (parent != -1 && low[v] >= disc[u]) {
                    ap[u] = 1;  // mark as AP
                }
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Root node special case
        if (parent == -1 && children > 1) {
            ap[u] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V, -1), low(V, -1), ap(V, 0);
        vector<bool> visited(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, ap, timer);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i] == 1) result.push_back(i);
        }

        if (result.empty()) result.push_back(-1);
        return result;
    }
};
