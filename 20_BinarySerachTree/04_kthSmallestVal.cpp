// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
    public:
        int kthSmallest(TreeNode* root, int& k) {
            if(root==NULL) return -1;
            
            // inorder
            int leftAns = kthSmallest(root->left, k);   // L
    
            if(leftAns != -1){
                return leftAns;
            }
    
            k--;    // N
            if(k==0){
                return root->val;   
            }
    
            int rightAns = kthSmallest(root->right, k); // R
            
            return rightAns;
        }
    };