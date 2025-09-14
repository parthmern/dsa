// https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1

class Solution {
  public:

    TNode* buildBST(LNode* &head, int n) {
        if(n <= 0 || head == NULL) return NULL;

        // build left subtree with n/2 nodes
        TNode* leftSubtree = buildBST(head, n/2);

        // current head becomes root
        TNode* root = new TNode(head->data);
        root->left = leftSubtree;

        // move forward
        head = head->next;

        // build right subtree with remaining nodes
        root->right = buildBST(head, n-n/2-1);

        return root;
    }

    TNode* sortedListToBST(LNode* head) {
        
        int n = 0;
        LNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        return buildBST(head, n);
    }
};
