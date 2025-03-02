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

Node* findNodeInBST(Node* root, int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data==target){
        return root;
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


Node* deleteNodeInBST(Node* root, int target){
    // base case
    if(root==NULL){
        return root;
    }

    if(root->data == target){
        // isi ko delete karna he
        /// 4 case

        if(root->left == NULL && root->right ==NULL){
            delete root;
            return NULL;
        }else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            delete root;
            return child;
        }else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            delete root;
            return child;
        }else{
            // both child existed
            // inorder predecessor of left sub tree -> left sub tree max val
            int inorderPres = maxVal(root->left);
            root->data = inorderPres;
            root->left = deleteNodeInBST(root->left, inorderPres);
            return root;
        }
    }else if(target> root->data){
        root->right = deleteNodeInBST(root->right, target);
    }else{
        root->left = deleteNodeInBST(root->left, target);
    }

    return root;    
}

Node* bstUsingInorder(int inorder[], int s, int e){
    if(s>e){
        return NULL; // invalid array
    }
    int mid = (s+e)/2;
    int ele = inorder[mid];
    Node* root = new Node(ele); 

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);

    return root;

}


int main() {
    // Node* root = NULL;
    // cout << "Enter data for ROOT node (enter -1 to stop): ";
    // takeInput(root);

    // cout << "Level Order Traversal of BST: ";
    // levelOrderTraversal(root);

    // cout << "searching" << endl;
    // cout << findNodeInBST(root, 155);

    // cout << "Min val" << minVal(root) << endl;
    // cout << "Max val" << maxVal(root) << endl;

    // cout << "deletion" << endl;
    // deleteNodeInBST(root, 100);

    // cout << "Level Order Traversal of BST: ";
    // levelOrderTraversal(root);

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    Node* rootNew = bstUsingInorder(inorder,0,8);

    cout << "Level Order Traversal of BST: ";
    levelOrderTraversal(rootNew);


    return 0;
}
