// https://leetcode.com/problems/merge-k-sorted-lists/

class Compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:

    priority_queue<ListNode*, vector<ListNode*>, Compare > minHeap;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        // 1) first Node push into minHeap
        for(int i=0; i<k; i++){
            ListNode* head = lists[i];
            if(head != NULL){
                minHeap.push(head);
            }
        }

        // ans LL
        ListNode* HEAD = NULL;
        ListNode* TAIL = NULL;

        while(minHeap.size() > 0){
            ListNode* top = minHeap.top();
            minHeap.pop();
            
            if(HEAD == NULL){
                // intial time when ans LL is empty
                HEAD = top;
                TAIL = top;
                
                if(HEAD->next != NULL){
                    minHeap.push(HEAD->next);
                }

            }else{
                TAIL->next = top;
                TAIL = top;

                if(TAIL->next != NULL){
                    minHeap.push(TAIL->next);
                }
            }
        }
        return HEAD;

        
    }
};