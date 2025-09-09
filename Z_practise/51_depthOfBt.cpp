/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, int count){
        if(root==NULL){
            cout << "null count" << count << endl;
            return count;
        };
        int left = solve(root->left, count+1);
        int right = solve(root->right, count+1);
        int maxi = max(left, right);
        return maxi;
    }

    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }
};