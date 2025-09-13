/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
  
    int solve(Node* root){
          if(root == NULL) {
            return 0;
        }
        
        if(root->left == NULL && root->right ==NULL){
            // leaf node
            int data = root->data;
            root->data = 0;
            return data;
        }
        
        int leftSum  = solve(root->left);
        int rightSum = solve(root->right);
        
        int data = root->data;
        root->data = leftSum + rightSum;
        return data+root->data;
        
    }

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        solve(node);
      
    }
};