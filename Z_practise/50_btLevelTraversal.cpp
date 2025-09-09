/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int> > ans;
    queue<Node *> q;
    
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            
            for(int i=0; i<q.size(); i++){
                Node* front = q.front();   q.pop();
                temp.push_back(front->data);
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
            
            ans.push_back(temp);
        }    
        
        return ans;
    }
};