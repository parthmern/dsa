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
    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a,b)-> a.val-b.val);

        for(int i=0; i<lists.length; i++){
            ListNode temp = lists[i];
            if(temp!=null) minHeap.add(temp);
        }

        ListNode head = null;
        ListNode tail = null;

        while(!minHeap.isEmpty()){
            if(head == null) {
                ListNode front = minHeap.poll();
                head = front;
                tail = front;
                if(front.next != null){
                    minHeap.add(front.next);
                }
            }else{
                ListNode front = minHeap.poll();
                tail.next = front;
                tail = front;
                if(front.next != null){
                    minHeap.add(front.next);
                }
            }
            
        }

        return head;
        

        

        
        
        
    }
}