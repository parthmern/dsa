// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

class Solution {
    public:
      vector<int> diagonal(Node *root) {
          vector<int> ans;
          queue<Node*> q;
          
          q.push(root);
          
          while(!q.empty()){
              Node* temp = q.front();
              q.pop();
              
              while(temp){
                  ans.push_back(temp->data);
                  if(temp->left){
                      q.push(temp->left); // baad me dekhenge
                  }
                  temp = temp->right;
              }
          }
          
          return ans;
          
      }
  };