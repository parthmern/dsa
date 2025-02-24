// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> ans;
    
            // first window
            for(int i=0; i<k; i++){
                // chote element delete kar do
                while(!dq.empty() && nums[i]>=nums[dq.back()]){
                    dq.pop_back();
                }
                // insering index so we can check out of window element
                dq.push_back(i);
            }
    
            // store ans of first window
            ans.push_back(nums[dq.front()]);
    
            // remaining windows process
            for(int i=k; i<nums.size(); i++){
                // out of window ele ko remove
                if(!dq.empty() && i-dq.front() >= k){
                    dq.pop_front();
                }
    
                // ab firse current ele k liye chote ele ko remove karna he
                while(!dq.empty() && nums[i]>=nums[dq.back()]){
                    dq.pop_back();
                }
                // insering index so we can check out of window element
                dq.push_back(i);
    
                // current window ka ans store karna
                ans.push_back(nums[dq.front()]);
            }
    
            return ans;
        }
    };