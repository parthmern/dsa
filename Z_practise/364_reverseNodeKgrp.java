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

class Pair{

    ListNode curr;
    ListNode nextN;

    Pair(ListNode c, ListNode n){
        this.curr = c;
        this.nextN = n;
    }

}

class Solution {

    private int size(ListNode head){
        ListNode curr = head;
        int c = 0;
        while(curr!=null){
            c++;
            curr=curr.next;
        }
        return c;
    }

    private ListNode reverseList(ListNode head, int k) {

        int size = this.size(head);

        
        ListNode currNode = head;
        if(head == null || head.next == null ) return head;

        ListNode nextNode = head.next;
        currNode.next = null;

     
        System.out.println("size -" + size);

        if(size >= k){
                    while(k!=1 && nextNode != null){
            ListNode temp = nextNode.next;
            nextNode.next = currNode;
            currNode = nextNode;
            nextNode = temp;
            k--;
        }
        }




        //System.out.println("next-" + nextNode.val);
        head.next = nextNode;
        return currNode;

    }

    private void printLL(ListNode head){
        ListNode curr = head;
        while(curr!=null){
            System.out.print(curr.val + " ->");
            curr=curr.next;
        }
        System.out.println("");
    }


    public ListNode reverseKGroup(ListNode head, int k) {

        if(head == null) return head;
    
        ListNode prev = head;
        ListNode reverseKaHead = reverseList(head, k);
        // prev.next = 
        printLL(reverseKaHead);
        prev.next = reverseKGroup(prev.next, k);
        return reverseKaHead;
    }
}