/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
} */

class Solution {
    int getMiddle(Node head) {
        // code here
        Node slow = head;
        Node fast = head;
        
        while( fast != null && slow !=null ){
            
            fast = fast.next;    
            if(fast == null ) return slow.data;
        
            fast = fast.next;
            
            slow = slow.next;
        }
        
        return slow.data;
        
    }
}