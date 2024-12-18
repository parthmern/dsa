// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1} ; //minDist, maxDist

        ListNode* prev = head;
        if(prev == NULL) return ans;

        ListNode* curr = head->next;
        if(curr == NULL) return ans;

        ListNode* nextNode = head->next->next;
        if(nextNode == NULL) return ans;

        int firstCp = -1;
        int lastCp = -1;

        int minDist = INT_MAX;
        int i = 1;

        while(nextNode != NULL){
            bool isCp = ((curr->val > prev->val && curr->val > nextNode->val) || (curr->val < prev->val && curr->val < nextNode->val)) ? true : false;

            if( isCp && firstCp == -1 ){
                // first cp got
                firstCp = i;
                lastCp = i;
            }
            else if(isCp){
                // means two cp mile he
                minDist = min(minDist, i-lastCp);
                lastCp = i;
                
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            nextNode = nextNode->next;
        }

        if(firstCp == lastCp){
            // only one cp found
            return ans;
        }else{
            ans[0] = minDist;
            int maxDist = lastCp-firstCp;
            ans[1] = maxDist;
            return ans;
        }

        


    }
};
