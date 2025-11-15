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

    public ListNode merge(ListNode l1, ListNode l2){
        if(l1==null) return l2;
        if(l2==null) return l1;

        ListNode ansHead = new ListNode(-1);
        ListNode ansTail = ansHead;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                ansTail.next = l1;
                ansTail = l1;
                l1=l1.next;
            }else{
                ansTail.next = l2;
                ansTail = l2;
                l2 = l2.next;
            }
        }

        if(l1!=null){
            ansTail.next = l1;
        }

        if(l2!=null){
            ansTail.next = l2;
        }

        return ansHead.next;



    }    

    public ListNode findMid(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
    
        if(fast != null){
            
            fast = fast.next;
            if(fast.next != null){
                fast = fast.next;
                slow = slow.next;
            }
            
        }

        return slow;

    }

    public ListNode helper( ListNode head ){

        if(head == null || head.next == null){
            return head;
        }

        ListNode mid = findMid(head);
        ListNode left = head;
        ListNode right = mid.next;

        mid.next = null;

        left = helper(left);
        right = helper(right);

        ListNode ans = merge(left, right);

        return ans;
    
    }

    public ListNode sortList(ListNode head) {
        return helper(head);
    }
}