// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
    public:
    
        int height(TreeNode* root) {
                if(root==NULL) return 0;
        
                int leftHeigth = height(root->left);
                int rightHeight = height(root->right);
        
                int heigth = max(leftHeigth, rightHeight) + 1;
        
                return heigth;
            }
    
        int diameterOfBinaryTree(TreeNode* root) {
    
            if(root==NULL) return 0;
    
            int option1 = diameterOfBinaryTree(root->left);
            int option2 = diameterOfBinaryTree(root->right);
            int option3 = height(root->left) + height(root->right);
    
            int diameter = max(option1, max(option2, option3));
    
            return diameter;
            
        }
    };