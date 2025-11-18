class Solution {
    public void reverseQueue(Queue<Integer> q) {
   
        if(q.isEmpty()) return;
        
        Integer ele = q.poll();
        
        reverseQueue(q);
        
        q.add(ele);
        
        return;
    
    }
}