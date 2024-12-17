// https://leetcode.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {

        if (list1 == 0)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTail = ansHead;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {

                ansTail->next = list1;

                ansTail = list1;

                list1 = list1->next;
            } else {

                ansTail->next = list2;

                ansTail = list2;

                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            ansTail->next = list1;

            ansTail = list1;

            list1 = list1->next;
        }

        while (list2 != NULL) {
            ansTail->next = list2;

            ansTail = list2;

            list2 = list2->next;
        }

        return ansHead->next;
    }

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {

        if( head == NULL || head->next == NULL ){
            return head;
        }

        // break ll into two part 
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        // sort RE
        left = sortList(left);
        right = sortList(right);

        // megre left-right
        ListNode* mergeLL = merge(left, right);
        return mergeLL;
        
    }
};