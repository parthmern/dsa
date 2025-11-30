// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
public:

    void bfs(vector<vector<int>> &adj, unordered_map<int, bool> &isVisited, vector<int> &ans, int node) {
        queue<int> q;
        q.push(node);
        isVisited[node] = true;   // fix assignment

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            // traverse all neighbours of front node
            for (auto i : adj[front]) {
                if (!isVisited[i]) {
                    q.push(i);
                    isVisited[i] = true; 
                }
            }
        }
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> ans;
        unordered_map<int, bool> isVisited;
        int vertex = adj.size();
        
        // traverse all componentes of graph
        for (int i = 0; i < vertex; i++) {
            if (!isVisited[i]) {
                bfs(adj, isVisited, ans, i);
            }
        }

        return ans;
    }
    
};
