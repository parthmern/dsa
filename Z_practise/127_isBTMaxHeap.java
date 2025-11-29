/*
class Node {
    int data;
    Node left,right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    
    public boolean isMaxHeap(Node root){
        
        if(root == null) return true;
        
        int largest = root.data;
        int prevAns = largest;
        
        if(root.left != null){
            largest = Math.max(largest, root.left.data);
        }
        
        if(largest != prevAns) return false;
        
        if(root.right != null){
            largest = Math.max(largest, root.right.data);
        }
        
        if(largest != prevAns) return false;
        
        return isMaxHeap(root.left) && isMaxHeap(root.right);
        
    }
    
   boolean isCBT(Node root) {
    if (root == null) return true;

    Queue<Node> q = new LinkedList<>();
    q.add(root);
    boolean seenNull = false;

    while (!q.isEmpty()) {
        Node curr = q.poll();

        if (curr == null) {
            seenNull = true;
        } else {
            if (seenNull) return false; 
            
            q.add(curr.left);
            q.add(curr.right);
        }
    }
        return true;
    }

    
    public boolean isHeap(Node tree) {
       
        return isCBT(tree) && isMaxHeap(tree);
        
    }
}