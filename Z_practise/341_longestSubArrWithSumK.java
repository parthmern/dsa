class Solution {
    public int longestSubarray(int[] arr, int k) {
        // code here
        
        Map<Integer, Integer> mp = new HashMap<>(); // prefixsum, index it occurs
        
        int sum = 0;
        int ans = 0;
        
        
        int i=0;
        for(int ele: arr){
            
            sum+=ele;
            
            if(sum == k){
                ans = Math.max(ans, i+1);
            }
            
            
            if(mp.containsKey(sum-k)){
                int index = mp.get(sum-k);
                ans = Math.max(ans, i-index);
            }
            
            if(!mp.containsKey(sum)){
                mp.put(sum, i);
            }
            
            
            i++;
            
            //System.out.println(mp+" "+sum+" "+ i);
        }
        
        
        return ans;
        
    }
}
