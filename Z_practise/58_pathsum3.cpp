class Solution {
public:

    int ans=0;

    void targetSumFuncRoot(TreeNode* root, long long currSum, long long ts){
        if(root==NULL) return;

        // cout << "At targetSumFuncRoot " << root->val << " sum " << currSum+root->val << endl;

        if(currSum+root->val == ts){
            ans = ans + 1;
        }

        targetSumFuncRoot(root->left, currSum + root->val, ts);
        targetSumFuncRoot(root->right, currSum + root->val, ts);
    }

    void targetSumFunc(TreeNode* root, long long currSum, long long ts){
        if(root==NULL) return;

        // cout << "At " << root->val << " sum " << currSum+root->val << endl;

        if(currSum+root->val == ts){
            ans = ans + 1;
        }

        targetSumFunc(root->left, currSum + root->val, ts);
        targetSumFunc(root->right, currSum + root->val, ts);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        long long sum = 0;
        if(root){
            targetSumFuncRoot(root, sum, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};
