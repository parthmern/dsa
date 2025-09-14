/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root==NULL) return NULL;

        if(root==p) return p;
        if(root==q) return q;

        TreeNode* LA = solve(root->left, p, q);
        TreeNode* RA = solve(root->right, p, q);

        if((LA == p && RA == q) || (LA==q && RA==p)) return root;
        if(LA!=NULL) return LA;
        if(RA!=NULL) return RA;
        
        return NULL;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};