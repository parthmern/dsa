/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return head;

        Node* temp = head;
        while (temp != NULL) {
            Node* nextOriginalNode = temp->next;
            Node* newCopyNode = new Node(temp->val);
            newCopyNode->next = nextOriginalNode;
            temp->next = newCopyNode;
            temp = nextOriginalNode;
        }

        temp = head;
        while (temp != NULL && temp->next != NULL) {
            Node* nextJump = temp->next->next;
            Node* pointingNode =
                (temp->random == NULL) ? NULL : (temp->random->next);
            temp->next->random = pointingNode;
            temp = nextJump;
        }

        temp = head;
        Node* ans = head->next;

        Node* prev = head;
        Node* curr = head->next;
        while (prev != NULL) {
            prev->next = curr->next;
            if (curr->next)
                curr->next = curr->next->next;

            prev = prev->next;
            curr = curr->next;
        }

        return ans;
    }
};