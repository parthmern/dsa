// https://leetcode.com/problems/rotate-list/


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

    ListNode* getTail(ListNode* head){
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }

    int getLen(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* getPrev(ListNode* head, ListNode* tail){
        ListNode* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        // ListNode* head = head;
        ListNode* tail = getTail(head);

        int updatedK = k % getLen(head);
        while(updatedK--){
            ListNode* prev = getPrev(head,tail);
            prev->next = NULL;

            ListNode* tailNode = tail;
            tailNode->next = head;

            tail = prev;
            head = tailNode;
        }

        return head;
        
    }
};