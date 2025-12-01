// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // undirected
        }

        vector<int> dist(V, -1);  // distance array
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (dist[nbr] == -1) {  // not visited
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        return dist;
    }
};
