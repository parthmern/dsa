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

    int height(TreeNode* root, int count){
        if(root==NULL) return count;
        int left = height(root->left, count+1);
        int right = height(root->right, count+1);
        int ans = max(left,right);
        return ans;
    }

    bool solve(TreeNode* root){
        if(root==NULL) return true;
        int leftH = height(root->left, 0);
        int rightH = height(root->right, 0);
        int leftRightDiff = (abs(leftH-rightH) <= 1);
        
        bool leftNode = solve(root->left);
        bool rightNode = solve(root->right);

        return leftNode && rightNode && leftRightDiff;

    }

    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};