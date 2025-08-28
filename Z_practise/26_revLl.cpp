class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while(current != NULL){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;

    }
};