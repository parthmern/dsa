import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        Deque<Integer> dq = new ArrayDeque<>();

        int s = nums.length - k + 1;
        int[] ans = new int[s];

        for(int i = 0; i < nums.length; i++){

            int windowLeft = i - k + 1;

            while(!dq.isEmpty() && dq.peekFirst() < windowLeft){
                dq.pollFirst();
            }

            while(!dq.isEmpty() && nums[dq.peekLast()] < nums[i]){
                dq.pollLast();
            }

            dq.addLast(i);

            if(i >= k - 1){
                ans[windowLeft] = nums[dq.peekFirst()];
            }
        }

        return ans;
    }
}