/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node reverseList(Node head) {
        // code here
        
        if( head == null || head.next == null ) return head;
        
        Node prev = null;
        Node curr = head;
        
        while(curr != null){
            Node temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
        
    }
}

// -------------------

class Solution {
    
    
    Node helper(Node prev, Node curr){
        if(curr == null){
            return prev;
        }
        
        Node temp = curr.next;
        curr.next = prev;
        
        return helper( curr, temp);
        
    }
    
    
    Node reverseList(Node head) {
    
        if( head == null || head.next == null ) return head;
        return helper(null, head);
        
    }
}