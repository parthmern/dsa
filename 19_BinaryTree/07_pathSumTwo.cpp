// https://leetcode.com/problems/path-sum-ii

class Solution {
    public:
    
        void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> temp, int sum){
            if(root==NULL){
                return;
            }
    
            sum = sum + root->val;
            temp.push_back(root->val);
    
            if(root->left==NULL && root->right==NULL){
                // leaf node
                if(sum==targetSum){
                    ans.push_back(temp);
                }else{
                    return;
                }
            }
    
            solve(root->left, targetSum, ans, temp, sum);
            solve(root->right, targetSum, ans, temp, sum);
    
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> ans;
            vector<int> temp;
            int sum=0;
            solve(root, targetSum, ans, temp, sum);
    
            return ans;
        }
    };