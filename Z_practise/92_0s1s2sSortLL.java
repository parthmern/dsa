/*
class Node {
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}*/

class Solution {
    
    
        
    public Node segregate(Node head) {
        
        Node head0s = new Node(-1);
        Node head1s = new Node(-1);
        Node head2s = new Node(-1);
        
        Node temp0s = head0s;
        Node temp1s = head1s;
        Node temp2s = head2s;
        
        Node curr = head;
        
        while(curr != null){
                
            Node temp = curr;
            curr = curr.next;
            temp.next = null;
                
            if(temp.data == 0){
                temp0s.next = temp;
                temp0s = temp0s.next;
               
            }else if(temp.data == 1){
                temp1s.next = temp;
                temp1s = temp1s.next;
              
            }else if(temp.data == 2){
                temp2s.next = temp;
                temp2s = temp2s.next;
              
            }
        }
        
        
        temp0s.next = (head1s.next != null) ? head1s.next : head2s.next;
        temp1s.next = head2s.next;

        return head0s.next;
        
        
        
        
      
        
        
    }
}