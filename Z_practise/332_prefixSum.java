class Solution {
    int maxLength(int arr[]) {

        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);  

        int prefixSum = 0;
        int maxLen = 0;
        
        
        for(int i=0; i<arr.length; i++){
            
            int ele = arr[i];
            
            prefixSum += ele;
            
            if(mp.get(prefixSum) == null ){
                mp.put(prefixSum, i);
            }else{
                maxLen = Math.max(maxLen, i - mp.get(prefixSum) );
                mp.put(prefixSum, Math.min(i, mp.get(prefixSum)));
            }
            
        }


        return maxLen;
    }
}
