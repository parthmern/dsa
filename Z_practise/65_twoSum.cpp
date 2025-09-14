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

    vector<int> arr;

    void fill(TreeNode* root){
        if(root==NULL) return;
        fill(root->left);
        arr.push_back(root->val);
        fill(root->right);
    }

    bool solve(int k){
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            cout << "sum for" << arr[s] << " " << arr[e] << "=" << arr[s]+arr[e] << endl;
            int sum = arr[s] + arr[e];
            if(sum==k){
                return true;
            }
            if(sum<k){
                s++;
            }else{
                e--;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        if(root->left==NULL && root->right==NULL) {
            return false;
        }
        fill(root);
        return solve(k);
    }
};