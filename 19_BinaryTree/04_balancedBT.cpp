// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
    public:
    
        int height(TreeNode* root) {
                if(root==NULL) return 0;
        
                int leftHeigth = height(root->left);
                int rightHeight = height(root->right);
        
                int heigth = max(leftHeigth, rightHeight) + 1;
        
                return heigth;
            }
    
        bool isBalanced(TreeNode* root) {
            
            if(root == NULL) {
                return true;
            }
    
            // current node ans 
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            int diff = abs(leftHeight-rightHeight);
    
            bool currentNodeAns = (diff <= 1);
    
            // left sub tree ans
            bool leftAns = isBalanced(root->left);
    
            // right sub tree ans 
            bool rightAns = isBalanced(root->right);
    
            return currentNodeAns && leftAns && rightAns;
            
        }
    };