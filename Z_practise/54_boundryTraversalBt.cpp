/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    vector<int> leftView;
    
    
    // vector<vector<int>> levels;
    // queue<Node*> q;
    
    // void levelView(Node* root){
    //     q.push(root);
    //     while(!q.empty()){
    //         vector<int> lvl;
    //         int levelSize = q.size();
    //         while(levelSize--){
    //             Node* frontEle = q.front();
    //             if(frontEle->left) q.push(frontEle->left);
    //             if(frontEle->right) q.push(frontEle->right);
    //             lvl.push_back(frontEle->data);
    //             q.pop();
    //         }
    //         levels.push_back(lvl);
    //     }
        
    //     for(auto val: levels){
    //         for(auto v: val){
    //             cout << v << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    
    
    void leftTraversal(Node* root){
        
        if(root->left == NULL && root->right == NULL){
            // leaf node
            return;
        }
        
        leftView.push_back(root->data);
        
        if(root->left != NULL){
            leftTraversal(root->left);
        }else{
            leftTraversal(root->right);
        }
    }
    
    void leafTraversal(Node* root){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            leftView.push_back(root->data);
        }
        
        leafTraversal(root->left);
        leafTraversal(root->right);
    }
    
    
    void rightTraversal(Node* root){
        
        if(root->left == NULL && root->right == NULL){
            // leaf node
            return;
        }
        
        int data = root->data;
        
        if(root->right != NULL){
            rightTraversal(root->right);
        }else{
            rightTraversal(root->left);
        }
        leftView.push_back(data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        leftView.push_back(root->data);
        if(root->left!=NULL)leftTraversal(root->left);
        if(root->left != NULL || root->right != NULL){
            leafTraversal(root);
        }
        if(root->right!=NULL)rightTraversal(root->right);
        
        return leftView;
        
    }
};