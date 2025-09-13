// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  
    int find(vector<int> &inorder, int ele){
        for(int i=0; i<inorder.size(); i++){
            if(ele == inorder[i]){
                return i;
            }
        }
    }
  
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &preIdx, int inS, int inE){
        
        if( preIdx >= preorder.size() || inS > inE ){
            return NULL;
        }
        
        Node * rootNode = new Node(preorder[preIdx]);
        int sameEleIdxInInorder = find(inorder, rootNode->data);
        preIdx=preIdx+1;
        rootNode->left = solve(inorder, preorder, preIdx, inS , sameEleIdxInInorder-1);
        rootNode->right = solve(inorder, preorder, preIdx, sameEleIdxInInorder+1, inE );
        
        return rootNode;
        
    }
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        
        int pre = 0;
        return solve(inorder, preorder, pre, 0, inorder.size()-1);
        
    }
};