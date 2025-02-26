// https://www.geeksforgeeks.org/print-left-view-binary-tree/

class Solution {
    public:
    
      void solve(Node *root, int level, vector<int>& ans){
          if(root==NULL) return;
          if(level == ans.size()){
              ans.push_back(root->data);
          }
          solve(root->left, level+1, ans);
          solve(root->right, level+1, ans);
      }
      vector<int> leftView(Node *root) {
          // code here
          vector<int> leftView;
          solve(root, 0, leftView);
          return leftView;
      }
  };