/* Structure of LinkedList
class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data = d;
        next = null;
    }
}
*/
class Solution {
    boolean isCircular(Node head) {
        // Your code here
        
        Node temp = head;
        
        Node it = head.next;
        
        while( it != null && it != head ){
            it = it.next;
        }
        
        if(it == head){
         return true;   
        }
        
        return false;
        
        
    }
}