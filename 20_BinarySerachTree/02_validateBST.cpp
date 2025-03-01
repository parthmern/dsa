// https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
    public:
    
        bool solve(TreeNode* root, long long int lb, long long int ub){
            if(root==NULL) return true;
    
            if(root->val > lb && root->val < ub){
                bool leftAns = solve(root->left, lb, root->val);
                bool rightAns = solve(root->right, root->val, ub);
                return leftAns && rightAns;
            }else{
                return false;
            }
        }
    
        bool isValidBST(TreeNode* root) {
            long long int LOWERBOUND = LLONG_MIN;
            long long int UPPERBOUND = LLONG_MAX;
            bool ans = solve(root, LOWERBOUND, UPPERBOUND);
            return ans;
        }
    };