// https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution {
public:

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: build adjacency list
        unordered_map<int, list<int>> adj;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);  // u -> v
        }

        // Step 2: compute indegree of each node
        vector<int> indegree(V, 0);
        for (auto &p : adj) {
            for (auto node : p.second) {
                indegree[node]++;
            }
        }

        // Step 3: push all nodes with indegree 0 to queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: BFS (Kahn’s Algorithm)
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return topo;
    }
};
