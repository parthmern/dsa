class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        
        Queue<Integer> q2 = new LinkedList<>();
        
        int size = q.size();
        int half = size/2;
        
        for(int i=0; i<half; i++){
            int data = q.remove();
            q2.add(data);
        }
        
        //System.out.println("q2->" + q2);
        
        while(!q2.isEmpty() ){
            int q2Data = q2.remove();
            q.add(q2Data);
            int qData = q.remove();
            q.add(qData);
        }
        
    }
}
