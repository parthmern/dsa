// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int node, unordered_map<int, bool> &isVisited, 
             vector<vector<int>> &graph, int n) {

        isVisited[node] = true;

        for (int j = 0; j < n; j++) {
            if (graph[node][j] == 1 && !isVisited[j]) {
                dfs(j, isVisited, graph, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // code here
        int n = isConnected.size();

        unordered_map<int, bool> isVisited;
        int provinces = 0; 

        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                provinces++;
                dfs(i, isVisited, isConnected, n);
            }
        }

        return provinces; // no of components
    }
};
