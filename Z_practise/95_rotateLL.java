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

    public static int n;

    public ListNode ans;

    public void findLastKthNode(ListNode head) {
        if (head == null)
            return;

        head = head.next;
        findLastKthNode(head);
        
        
        if (this.n == 0) {
            this.ans = head;
        }
        if(head!=null){
            System.out.println("head" + head.val + " " + n);    
        }
        
        n--;
        

        return;

    }

    public int length(ListNode head) {
        int count = 0;
        while (head != null) {
            head = head.next;
            count++;
        }

        return count;
    }

    public ListNode rotateRight(ListNode head, int k) {

        if(head == null) return head;
        if(k==0) return head;

        // n.clear();
        n = 0;
        ans = null;
        // ans.clear();

        int len = length(head);
        //System.out.println("len" + len + " " + (len % k)+1);
        if (len == k || len ==1 || len == k) return head;
        this.n = (k > len) ? ((k%len)+1 ): (k+1);
        if(this.n==1) return head;
        System.out.println("final n" + n);
        findLastKthNode(head);

        ans = (ans==null) ? (head) : ans;

        if (ans != null) {
            System.out.println("ans" + ans.val);
            ListNode prev = ans;
            ListNode finalHead = ans.next;
            ListNode curr = ans.next;

            prev.next = null;
            while (curr.next != null) {
                curr = curr.next;
            }

            System.out.println("prev " + prev.val + "curr " + curr.val);

            curr.next = head;
            return finalHead;
        } else {
            return head;
        }

    }
}