/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;

    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        for(auto val: inorder) cout << val << " ";
        return inorder[k-1];
    }
};

// ========================================================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans;
    void solve(TreeNode* root, int &k){

        if(root==NULL) return;

        solve(root->left, k);
        k--;
    
        if(k==0) {
            cout << " k zer " << root->val << endl;
            ans = root->val;
            return;
        }
        
        
        solve(root->right, k);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return ans;
    }
};