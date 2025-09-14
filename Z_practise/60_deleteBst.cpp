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
    int findMinVal(TreeNode* root){
        cout << "running for"<< root->val << endl;
        if(root->left == NULL){
            cout << "min val"<< root->val << endl;
            return root->val;
        }

        return findMinVal(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        if(root->val == key){

            if(root->left == NULL && root->right == NULL){
                cout << "hitted for" << root->val << endl;
                delete root;
                return NULL;
            }else if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == NULL && root->left != NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                // both has child
                int minVal = findMinVal(root->right);
                root->val = minVal;
                root->right = deleteNode(root->right, minVal);
                return root;
            }

        }else if(key>root->val){
            // right
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};