#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>1){
        // front fetch
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            q.push(NULL);
        }else{
            // valid
            cout << front->data << " ";

            // left 
            if(front->left != NULL){
                q.push(front->left);
            }
            // right 
            if(front->right != NULL){
                q.push(front->right);
            }
        }
        
    }
}

int main(){
    Node* root = createTree();
    preOrderTraversal(root);
    return 0;
}