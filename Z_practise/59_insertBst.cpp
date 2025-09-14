/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* solve(Node* root, int key){
        
        if(root==NULL){
            Node* temp = new Node(key);
            return temp;
        }
        
        if(root->data == key) return root;
        
        if( key < root->data ){
            root->left = solve(root->left, key);
        }
        else{
            root->right = solve(root->right, key);
        }
        
        return root;
    }
  
    Node* insert(Node* root, int key) {
        //  code  here
        
        return solve(root, key);
        
    }
};