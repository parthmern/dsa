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

    ListNode* findTail(ListNode* head){
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* findOneBeforeTail(ListNode* head){
        ListNode* prev = head;
        ListNode* curr = head->next==NULL ? NULL : head->next;
        while(curr!=NULL && curr->next!=NULL){
            prev=prev->next;
            curr=curr->next;
        }
        return prev;
    }

    int totalLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return NULL;

        ListNode* tail =  findTail(head);

        int len = totalLength(head);
        k = k>len ? k%len : k;

        while(k--){
            ListNode* prev = findOneBeforeTail(head);
            tail->next = head;
            prev->next = NULL;
            head = tail;
            tail = prev;
        } 

        return head;

    }
};