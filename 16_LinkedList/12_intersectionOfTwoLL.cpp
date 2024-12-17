class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        // First loop to traverse both lists
        while (a != NULL || b != NULL) {

            // If both pointers meet, return the intersection node
            if (a == b) {
                return a;
            }

            // Move to the next node or reset to the other list's head
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        // Calculate lengths if no intersection is found yet
        if (a == NULL && b == NULL) {
            ListNode* tempA = headA;
            ListNode* tempB = headB;

            int alen = 0, blen = 0;

            while (tempA != NULL) {  // Calculate the length of list A
                alen++;
                tempA = tempA->next;
            }
            while (tempB != NULL) {  // Calculate the length of list B
                blen++;
                tempB = tempB->next;
            }

            // Align the start of the two lists
            tempA = headA;
            tempB = headB;

            if (alen > blen) {
                for (int i = 0; i < (alen - blen); i++) {
                    tempA = tempA->next;
                }
            } else {
                for (int i = 0; i < (blen - alen); i++) {
                    tempB = tempB->next;
                }
            }

            // Traverse both lists together to find the intersection
            while (tempA != tempB) {
                tempA = tempA->next;
                tempB = tempB->next;
            }

            return tempA;  // Either intersection node or NULL
        }

        return NULL;  // No intersection found
    }
};
