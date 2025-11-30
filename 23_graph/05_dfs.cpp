// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
public:

    void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;      
        ans.push_back(node);      

        // visit all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n, false);

        // traverse all connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsUtil(i, adj, visited, ans);
            }
        }

        return ans;
    }
};
