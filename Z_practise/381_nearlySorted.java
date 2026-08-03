class Solution {
    public void nearlySorted(int[] arr, int k) {
        
        if(k>arr.length) return;
        if(k==0)return;
        
        // code here
        
        //int[] ans = new int[arr.length];
        List<Integer> ans = new ArrayList<>();
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0; i<k; i++){
            minHeap.add(arr[i]);
        }
        
        // after chekc
        for(int i=k; i<arr.length; i++){
            
            int ele = arr[i];
            if(minHeap.peek() < ele){
                ans.add(minHeap.remove());
                minHeap.add(ele);
            }else{
                ans.add(ele);
            }
            
        }
        
        while(!minHeap.isEmpty()) ans.add(minHeap.remove());
        
        for(int i=0; i<ans.size(); i++) arr[i] = ans.get(i);
        
    
        
    }
}
