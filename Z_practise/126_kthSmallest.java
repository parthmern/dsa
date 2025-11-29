class Solution {
    
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
    
    public void helper(int[] arr, int k){
        
        int i=0;
        
        while(i<k){
            maxHeap.add(arr[i]);
            i++;
        }
        
        while( i< arr.length){
            
            if(arr[i] < maxHeap.peek() ){
                maxHeap.poll();
                maxHeap.add(arr[i]);
            }
            
            i++;
        }
        
        //System.out.println(maxHeap);
        
    }
    
    public int kthSmallest(int[] arr, int k) {
       helper(arr, k);
       
    //   while(k != 1){
    //       maxHeap.poll();
    //       k--;
    //   }
       
       return maxHeap.peek();
       
        
    }
}
