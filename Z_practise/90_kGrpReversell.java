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

    public void printLL(ListNode head){
        
        ListNode temp = head;

        while( temp!=null ){
            System.out.print(temp.val + " ->");
            temp = temp.next;
        }

    }

    public int getLen(ListNode head){

        ListNode temp = head;
        int c = 0;

        while( temp!=null ){
            c++;
            temp = temp.next;
        }

        return c;
 
    }

    public ListNode helper(ListNode head, int k){
        
        if( getLen(head) < k ) return head;

        ListNode prev = null;
        ListNode curr = head;

        for(int i=0; i<k; i++){
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr= temp;
        }

        head.next =  helper(curr, k);
        return prev;

    }

    public ListNode reverseKGroup(ListNode head, int k) {
        return helper(head, k);
    }
}