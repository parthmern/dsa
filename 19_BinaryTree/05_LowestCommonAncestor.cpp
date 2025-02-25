// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL) return NULL;
    
            if(root->val==p->val) return p;
            if(root->val==q->val) return q;
    
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
    
            if(leftAns==NULL && rightAns==NULL){
                return NULL;
            }else if(leftAns!=NULL && rightAns==NULL){
                return leftAns;
            }else if(leftAns==NULL && rightAns!=NULL){
                return rightAns;
            }else{
                // both are not null so actual node is ans
                return root;
            }
    
        }
    };