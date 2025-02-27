// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

class Solution {
    public:
    
      int solve(Node* root){
          if(!root) return 0;
          
          if(root->left == NULL && root->right==NULL){    // leaf node
              int valOfNode = root->data;
              root->data = 0;
              return valOfNode;
          }
          
          int leftSum = solve(root->left);
          int rightSum = solve(root->right);
          
          int currentNodeVal = root->data;
          root->data = leftSum+rightSum;
          return currentNodeVal + (root->data);
          
      }
      void toSumTree(Node *node)
      {
          solve(node);
      }
  };