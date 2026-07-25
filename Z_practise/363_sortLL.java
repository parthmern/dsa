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

    private ListNode middleNode(ListNode head) {
        ListNode slow = head;
        if(head==null || head.next==null) return head;
        ListNode fast = head.next;

        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    private ListNode mergeTwoSortedLL(ListNode left, ListNode right){

        ListNode temp = new ListNode(-1);
        ListNode head = temp;
        
        while(left != null && right != null){
            if(left.val < right.val){
                temp.next = left;
                left = left.next;
                temp = temp.next;
            }
            else{
                temp.next = right;
                right = right.next;
                temp = temp.next;
            }
        }

        while(left != null){
            temp.next = left;
            left = left.next;
            temp = temp.next;
        }

        while(right != null){
            temp.next = right;
            right = right.next;
            temp = temp.next;
        }

        return head.next;

    }

    private void printLL(ListNode head){
        ListNode curr = head;
        while(curr!=null){
            System.out.print(curr.val + " ->");
            curr=curr.next;
        }
        System.out.println("");
    }

    private ListNode ms(ListNode head) {

        if(head == null || head.next == null) return head;

        //printLL(head);

        ListNode mid = this.middleNode(head);

        //System.out.println("mid " + mid.val);

        ListNode midNext = mid.next;
        mid.next = null;

        ListNode left = this.ms(head);
        ListNode right = this.ms(midNext);
        return this.mergeTwoSortedLL(left, right);

    }

    public ListNode sortList(ListNode head) {

        return this.ms(head);

    }
}