class Solution {
    public static int kthLargest(int[] arr, int k) {
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0; i<arr.length; i++){
            int sum = 0;
            for(int j=i; j<arr.length; j++){
                
                sum = sum + arr[j];
                
                if(minHeap.size() < k){
                    minHeap.add(sum);
                }else{
                    if(minHeap.peek() < sum){
                        minHeap.poll();
                        minHeap.add(sum);
                    }
                }
            }
        }
        
        
       // System.out.println(minHeap);
        
        return minHeap.peek();
        
    }
}
