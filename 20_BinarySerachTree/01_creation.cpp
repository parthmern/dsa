#include <iostream>
#include <queue> // For using queue in level order traversal

using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    // First node
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Not first node
    if (root->data > data) {
        // Insert at left
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

bool findNodeInBST(Node* root, int target){
    if(root==NULL){
        return false;
    }

    if(root->data==target){
        return true;
    }

    if(target > root->data){
        // right sub tree
        return findNodeInBST(root->right,target);
    }else{
        return findNodeInBST(root->left,target);
    }
}

int minVal(Node* root){
    Node* temp = root;

    if(temp == NULL){
        return -1;
    }

    while(temp->left != NULL){
        temp = temp->left; 
    }

    return temp->data;
}

int maxVal(Node* root){
    Node* temp = root;

    if(temp == NULL){
        return -1;
    }

    while(temp->right != NULL){
        temp = temp->right; 
    }

    return temp->data;
}

int main() {
    Node* root = NULL;
    cout << "Enter data for ROOT node (enter -1 to stop): ";
    takeInput(root);

    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(root);

    cout << "searching" << endl;
    cout << findNodeInBST(root, 155);

    cout << "Min val" << minVal(root) << endl;
    cout << "Max val" << maxVal(root) << endl;

    return 0;
}
