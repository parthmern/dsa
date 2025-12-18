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

    private int length(ListNode head){

        int len = 0;

        while(head != null){
            head = head.next;
            len++;
        }

        return len;

    }

    private ListNode helper(ListNode head, int k){

        if(head == null) return null;

        int len = length(head);
        System.out.println("len"+ len);


        if(len < k) return head;

        ListNode prev = null;
        ListNode curr = head;
        
       
        for(int i=0; i<k; i++){
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }

        //System.out.println("afterloop prev" + prev.val + "curr" + curr.val );

        if(head != null){
            head.next = helper(curr, k);
        }
        
        //System.out.println("returning" + prev.val);
        return prev;

    }
    
    public ListNode reverseKGroup(ListNode head, int k) {

       return helper(head, k);
        
    }
}