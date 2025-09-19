// https://www.geeksforgeeks.org/problems/bst-to-max-heap/1

// User function Template for C++
/*struct Node {
    int data;
    Node *left, *right;
};*/
class Solution {
  public:
    
    void storeInorderTraversal(Node* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        // LNR (Inorder)
        storeInorderTraversal(root->left, in);
        in.push_back(root->data);
        storeInorderTraversal(root->right, in);
    }

    void replaceUsingPostOrder(Node* root, vector<int>& in, int &index) {
        if (root == NULL) {
            return;
        }
        // LRN (Postorder)
        replaceUsingPostOrder(root->left, in, index);
        replaceUsingPostOrder(root->right, in, index);
        root->data = in[index++];
    }

    void convertToMaxHeapUtil(Node* root) {
        vector<int> inorder;
        storeInorderTraversal(root, inorder);
        int index = 0;
        replaceUsingPostOrder(root, inorder, index);
    }
};
