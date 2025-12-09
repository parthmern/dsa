// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // 1 Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // 2 Detect negative weight cycle
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                return { -1 };   // negative cycle present
            }
        }

        // 3 Replace INT_MAX with 10^8 (100000000)
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = 100000000;  // 1e8
        }

        return dist;
    }
};
