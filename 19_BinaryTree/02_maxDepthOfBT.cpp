// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root==NULL) return 0;
    
            int leftHeigth = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);
    
            int heigth = max(leftHeigth, rightHeight) + 1;
    
            return heigth;
        }
    };