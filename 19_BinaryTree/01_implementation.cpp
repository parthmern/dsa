#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

// returns Root node of created Tree
Node* createTree(){
    cout << "Enter val of ROOT:" << endl;
    int data;
    cin >> data;

    if(data == -1){ // means donot want to add node
        return NULL;
    }

    // 1)create node
    Node* root = new Node(data);

    // 2) create left sub tree
    cout << "For LEFT node of" << root->data << endl; 
    root->left = createTree();

    // 3) create right sub tree
    cout << "For RIGHT node of" << root->data << endl; 
    root->right = createTree();
    
    return root;
}

void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    // NLR

    // N 
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root==NULL) return;
    // LNR
    preOrderTraversal(root->left);
    cout << root->data << " ";
    preOrderTraversal(root->right);
}

void postOrderTraveral(Node* root){
    if(root==NULL) return;
    // LRN
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = createTree();
    preOrderTraversal(root);
    return 0;
}