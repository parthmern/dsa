/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {

        ArrayList<Integer> arr = new ArrayList<>();

        ListNode prev = head;
        ListNode curr = head.next;

        int index = 1;
        while (curr.next != null) {
            System.out.println("checking for" + curr.val);

            if (prev.val > curr.val && curr.next.val > curr.val) {
                arr.add(index);
            }

            if (prev.val < curr.val && curr.next.val < curr.val) {
                arr.add(index);
            }

            prev = curr;
            curr = curr.next;
            index++;

        }

        System.out.println(arr);

        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;

        for (int i = 0; i < arr.size() - 1; i++) {
            int temp = arr.get(i + 1) - arr.get(i);
            mini = Math.min(mini, temp);
        }

        if (arr.size() < 2) {
            mini = -1;
            maxi = -1;
        } else {
            maxi = arr.get(arr.size() - 1) - arr.get(0);
        }

        int ans[] = { mini, maxi };
        return ans;

    }
}