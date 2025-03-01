// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL) return root;
    
            if(p->val < root->val && q->val < root->val){   // case1
                return lowestCommonAncestor(root->left, p, q);
            }else if(p->val > root->val && q->val > root->val){ // case2
                return lowestCommonAncestor(root->right, p, q);
            }else{ //case3 and 4
                return root;
            }
        }
    };