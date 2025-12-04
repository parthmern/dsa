// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
public:


    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // adj list
        // vector<list<pair<int,int>>> adj(V); wrorks as well

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;   // min heap ele : pair<int,int>

        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &nbr : adj[node]) {
                int x = nbr.first;
                int wt = nbr.second;

                if (dist[node] + wt < dist[x]) {
                    dist[x] = dist[node] + wt;
                    pq.push({dist[x], x});
                }
            }
        }

        return dist;
    }
};
