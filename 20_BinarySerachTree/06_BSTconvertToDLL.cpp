// https://www.geeksforgeeks.org/convert-binary-tree-to-doubly-linked-list-using-inorder-traversal/

class Solution {
    public:
    
      void convertIntoDLL(Node* root, Node*& head){
          if(root==NULL) return;
       
          convertIntoDLL(root->right, head);
          root->right = head;
          if(head!=NULL){
              head->left = root;
          }
          
          // update head
          head = root;
          
          // -------------
          // LEFT Part
          convertIntoDLL(root->left, head);
      }
    
      Node* bToDLL(Node* root) {
          // code here
          Node* head = NULL;
          convertIntoDLL(root, head);
          return head;
      }
  };