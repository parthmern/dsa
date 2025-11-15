/* Structure of node
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
} */

class Solution {
    
    Node ans;

    public void helper(Node head, Common c ){

        if(head == null) return;

        head = head.next;
        helper( head, c );
       
        if( c.curr == 0 ){
            ans = head;
        }
        c.curr--;

        return ;

    }
    
    public int len(Node head){
        int c = 0;
        while(head!=null){
            head = head.next;
            c++;
        }
        return c;
    }

    // Function to find the data of kth node from
    // the end of a linked list.
    int getKthFromLast(Node head, int k) {
        // Your code here
        Node temp = head;
        int len = len(head);
        if(len<k){
            return -1;
        }
        
        Common c = new Common(k);
        
        helper(temp, c);
        return c.curr == 0 ? temp.data :  ans.data;
    }
}

class Common{
    public int curr;

    Common(int n){
        curr = n;
    }
    
}